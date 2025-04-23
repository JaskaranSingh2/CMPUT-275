#include "list.h"
#include <iostream>
#include <iomanip>
using namespace std;


int main() {
  List<List<char>> maze;
  char c = '\0';
  cin >> noskipws;
  cin >> c;
  while (c != '\n') {
    // Once we enter this loop c is the first character of
    // the next line.
    List<char> row;
    for (; c != '\n'; cin >> c) {
      row.push(c);
    }
    // When we see a newline, push that row into our maze.
    maze.push(row);
    cin >> c;
  }
  for (int i = 0; i < maze.length(); ++i) {
    for (int j = 0; j < maze[i].length(); ++j) {
      if (maze[i][j] == 'S') {
        maze[i][j] = 'P';
      }
    }
  }

  for (int i = 0; i < maze.length(); ++i) {
    cout << "|";
    for (int j = 0; j < maze[i].length(); ++j) {
      cout << maze[i][j];
    }
    cout << "|" << endl;
  }
}
