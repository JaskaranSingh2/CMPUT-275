#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze.h"

// This basically holds maze details and player position
struct Maze {
    char **grid;
    int rows;
    int cols;
    int startX, startY;
    int playerX, playerY;
    // Teleporters: each digit has two positions
    struct {
        int x1, y1, x2, y2;
    } teleporters[10];
};

// Helper to check if a character is a digit
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

struct Maze *readMaze() {
    char buffer[1024];
    struct Maze *maze = (struct Maze *)malloc(sizeof(struct Maze));
    maze->rows = 0;
    maze->cols = 0;
    int capacity = 10;
    maze->grid = (char **)malloc(capacity * sizeof(char *));

    // Read lines until a blank line
    while (fgets(buffer, 1024, stdin) && buffer[0] != '\n') {
        // Remove newline and check line length
        size_t len = strlen(buffer);
        if (buffer[len-1] == '\n') buffer[--len] = '\0';
        if (len == 0) continue;

        // Allocate space for the row
        if (maze->rows == capacity) {
            capacity *= 2;
            maze->grid = (char **)realloc(maze->grid, capacity * sizeof(char *));
        }
        maze->grid[maze->rows] = (char *)malloc(len + 1);
        strcpy(maze->grid[maze->rows], buffer);
        maze->rows++;
    }

    if (maze->rows == 0) {
        free(maze);
        return NULL;
    }
    maze->cols = strlen(maze->grid[0]);

    // Track 'S', 'G', and teleporters
    int sCount = 0, gCount = 0;
    int teleCount[10] = {0};

    for (int i = 0; i < maze->rows; i++) {
        for (int j = 0; j < maze->cols; j++) {
            char c = maze->grid[i][j];
            if (c == 'S') {
                maze->startX = j;
                maze->startY = i;
                sCount++;
            } else if (c == 'G') {
                gCount++;
            } else if (is_digit(c)) {
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
    if (sCount != 1 || gCount < 1) {
        destroyMaze(maze);
        return NULL;
    }

    // Check teleporters have pairs
    for (int i = 0; i < 10; i++) {
        if (teleCount[i] != 0 && teleCount[i] != 2) {
            destroyMaze(maze);
            return NULL;
        }
    }

    // Set initial player position
    maze->playerX = maze->startX;
    maze->playerY = maze->startY;
    return maze;
}

struct Pos makeMove(struct Maze *maze, char dir) {
    int dx = 0, dy = 0;
    switch (dir) {
        case 'n': dy = -1; break;
        case 's': dy = 1; break;
        case 'e': dx = 1; break;
        case 'w': dx = -1; break;
        default: return (struct Pos){maze->playerX, maze->playerY};
    }

    int newX = maze->playerX + dx;
    int newY = maze->playerY + dy;

    // Check boundaries and walls
    if (newX < 0 || newX >= maze->cols || newY < 0 || newY >= maze->rows ||
        maze->grid[newY][newX] == 'X') {
        return (struct Pos){maze->playerX, maze->playerY};
    }

    // Handle sliding on ice
    while (maze->grid[newY][newX] == 'I') {
        int nextX = newX + dx;
        int nextY = newY + dy;
        if (nextX < 0 || nextX >= maze->cols || nextY < 0 || nextY >= maze->rows ||
            maze->grid[nextY][nextX] == 'X') {
            break;
        }
        newX = nextX;
        newY = nextY;
    }

    // Check teleporter
    char tile = maze->grid[newY][newX];
    if (is_digit(tile)) {
        int num = tile - '0';
        if (newX == maze->teleporters[num].x1 && newY == maze->teleporters[num].y1) {
            newX = maze->teleporters[num].x2;
            newY = maze->teleporters[num].y2;
        } else {
            newX = maze->teleporters[num].x1;
            newY = maze->teleporters[num].y1;
        }
    }

    // Update player position
    maze->playerX = newX;
    maze->playerY = newY;

    // Check if reached goal
    if (maze->grid[newY][newX] == 'G') {
        return (struct Pos){-1, -1};
    }
    return (struct Pos){newX, newY};
}

void reset(struct Maze *maze) {
    maze->playerX = maze->startX;
    maze->playerY = maze->startY;
}

void printMaze(struct Maze *maze) {
    // Print top border
    printf("-");
    for (int i = 0; i < maze->cols; i++) printf("-");
    printf("-\n");

    for (int i = 0; i < maze->rows; i++) {
        printf("|");
        for (int j = 0; j < maze->cols; j++) {
            if (i == maze->playerY && j == maze->playerX) {
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
