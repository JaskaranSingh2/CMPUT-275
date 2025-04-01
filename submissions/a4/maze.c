#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"

// This holds maze details and player position
struct Maze {
    char **grid;
    int rows;
    int cols;
    int playerPositionX, playerPositionY; // Current player pos.
    int startingX, startingY;  // Starting position coord.
    
    // Teleporters: each digit has two positions
    struct {
        int x1, y1, x2, y2;
    } teleporters[10];
};

// check if a character is a digit, pretty simple
int isDigit(char c) {
    return c >= '0' && c <= '9';
}

struct Maze *readMaze() {
    char buffer[1024];
    struct Maze *maze = malloc(sizeof(struct Maze));
    maze->rows = 0;
    maze->cols = 0;
    int capacity = 10;
    maze->grid = malloc(capacity * sizeof(char *));

    // Read lines until a blank line
    while (fgets(buffer, 1024, stdin) && buffer[0] != '\n') {
        // Remove newline and check line length
        size_t len = strlen(buffer);
        if (buffer[len-1] == '\n') buffer[--len] = '\0';
        if (len == 0) continue;

        // Here we are allocating the space for the row
        if (maze->rows == capacity) {
            capacity *= 2;
            maze->grid = realloc(maze->grid, capacity * sizeof(char *));
        }
        maze->grid[maze->rows] = malloc(len + 1);
        strcpy(maze->grid[maze->rows], buffer);
        maze->rows++;
    }

    if (maze->rows == 0) {
        free(maze);
        return NULL;
    }
    maze->cols = strlen(maze->grid[0]);

    // Track 'S', 'G', alongside the teleporters
    int startCounter = 0, goalCounter = 0;
    int teleCount[10] = {0};

    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            char c = maze->grid[i][j];
            if (c == 'S') {
                maze->startingX = j;
                maze->startingY = i;
                startCounter++;
            } else if (c == 'G') {
                goalCounter++;
            } else if (isDigit(c)) {
                int num = c - '0';
                if (teleCount[num] == 0) {
                    maze->teleporters[num].x1 = j;
                    maze->teleporters[num].y1 = i;
                } else {
                    maze->teleporters[num].x2 = j;
                    maze->teleporters[num].y2 = i;
                }
                teleCount[num]++;
            }
        }
    }

    // Validate maze
    if (goalCounter < 1 || startCounter != 1) {
        destroyMaze(maze);
        return NULL;
    }

    // Check if the teleporters have pairs
    for (int i = 0; i < 10; i++) {
        if (teleCount[i] != 2 && teleCount[i] != 0) {
            destroyMaze(maze);
            return NULL;
        }
    }

    // Set initial player position
    maze->playerPositionX = maze->startingX;
    maze->playerPositionY = maze->startingY;
    return maze;
}

struct Pos makeMove(struct Maze *maze, char direction) {
    int dirX = 0, dirY = 0;
    switch (direction) {
        case 'n': dirY = -1; break;
        case 's': dirY = 1; break;
        case 'e': dirX = 1; break;
        case 'w': dirX = -1; break;
        default: return (struct Pos){maze->playerPositionX, maze->playerPositionY};
    }

    int newX = maze->playerPositionX + dirX;
    int newY = maze->playerPositionY + dirY;

    // Check boundaries and walls
    if (newX >= maze->cols || newX < 0 || newY < 0 || newY >= maze->rows ||
        maze->grid[newY][newX] == 'X') {
        return (struct Pos){maze->playerPositionX, maze->playerPositionY};
    }

    // This will handle the sliding on ice
    while (maze->grid[newY][newX] == 'I') {
        int nextX = newX + dirX;
        int nextY = newY + dirY;
        if (nextX < 0 || nextX >= maze->cols || nextY < 0 || nextY >= maze->rows ||
            maze->grid[nextY][nextX] == 'X') {
            break;
        }
        newX = nextX;
        newY = nextY;
    }

    // Check the teleporter
    char tile = maze->grid[newY][newX];
    if (isDigit(tile)) {
        int teleporterNum = tile - '0';
        if (newX == maze->teleporters[teleporterNum].x1 && newY == maze->teleporters[teleporterNum].y1) {
            newX = maze->teleporters[teleporterNum].x2;
            newY = maze->teleporters[teleporterNum].y2;
        } else {
            newX = maze->teleporters[teleporterNum].x1;
            newY = maze->teleporters[teleporterNum].y1;
        }
    }

    // Update player position
    maze->playerPositionX = newX;
    maze->playerPositionY = newY;

    // Check if reached goal
    if (maze->grid[newY][newX] == 'G') {
        return (struct Pos){-1, -1};
    }
    return (struct Pos){newX, newY};
}

void reset(struct Maze *maze) {
    maze->playerPositionX = maze->startingX;
    maze->playerPositionY = maze->startingY;
}

void printMaze(struct Maze *maze) {
    // Print top border
    printf("-");
    for (int i = 0; i < maze->cols; i++) printf("-");
    printf("-\n");

    for (int i = 0; i < maze->rows; i++) {
        printf("|");
        for (int j = 0; j < maze->cols; j++) {
            if (i == maze->playerPositionY && j == maze->playerPositionX) {
                printf("P");
            } else {
                printf("%c", maze->grid[i][j]);
            }
        }
        printf("|\n");
    }

    // Print bottom border
    printf("-");
    for (int i = 0; i < maze->cols; i++) printf("-");
    printf("-\n");
}

struct Maze *destroyMaze(struct Maze *maze) {
    if (maze) {
        for (int i = 0; i < maze->rows; i++) {
            free(maze->grid[i]);
        }
        free(maze->grid);
        free(maze);
    }
    return NULL;
}
