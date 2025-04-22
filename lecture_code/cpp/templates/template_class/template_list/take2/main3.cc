#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

// Our "growing array List" type actually already exists...
// it is called vector.

int main() {
  vector<vector<char>> maze;
  char c = '\0';
  cin >> noskipws;
  cin >> c;
  while (c != '\n') {
    // Once we enter this loop c is the first character of
    // the next line.
    vector<char> row;
    for (; c != '\n'; cin >> c) {
      row.emplace_back(c);
    }
    // When we see a newline, push that row into our maze.
    maze.emplace_back(row);
    cin >> c;
  }

  for (int i = 0; i < maze.size(); ++i) {
    cout << "|";
    for (int j = 0; j < maze[i].size(); ++j) {
      cout << maze[i][j];
    }
    cout << "|" << endl;
  }
}
