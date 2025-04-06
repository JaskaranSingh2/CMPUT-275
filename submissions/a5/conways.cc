#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Okay, so basically this function counts how many alive neighbors a cell has
int countNeighbors(const vector<vector<char>>& grid, int row, int col) {
    int count = 0;
    int rows = grid.size();
    int cols = grid[0].size();
    
    // We're gonna check all the cells around our target
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            // Skip the cell we're looking at
            if (i == 0 && j == 0) {
                continue;
            }
            
            int newRow = row + i;
            int newCol = col + j;
            
            // Make sure we're not looking outside the grid and stuff
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                if (grid[newRow][newCol] == 'O') {
                    count++;
                }
            }
        }
    }
    
    return count;
}

// This function basically moves the game forward one step
vector<vector<char>> advanceGrid(const vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    // We're making a new grid
    vector<vector<char>> newGrid = grid;
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = countNeighbors(grid, i, j);
            
            if (grid[i][j] == 'O') {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = '.';
                }
            } else {
                // If it's got exactly 3 neighbors
                if (neighbors == 3) {
                    newGrid[i][j] = 'O';
                }
            }
        }
    }
    
    return newGrid;
}

// This function just prints out what the grid looks like
void printGrid(const vector<vector<char>>& grid) {
    int cols = grid[0].size();
    
    for (int j = 0; j < cols; j++) {
        cout << '|';
    }
    cout << endl;
    
    // Now we're printing out all the cells and stuff
    for (const auto& row : grid) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }

    for (int j = 0; j < cols; j++) {
        cout << '|';
    }
    cout << endl;
}

int main() {
    vector<vector<char>> grid;
    string line;
    
    // We're reading in the initial grid setup
    while (getline(cin, line) && line != "x") {
        vector<char> row(line.begin(), line.end());
        grid.push_back(row);
    }
    
    char command;
    while (cin >> command) {
        if (command == 'p') {
            printGrid(grid);
        } else if (command == 's') {
            grid = advanceGrid(grid);
        }
    }
    
    return 0;
}
