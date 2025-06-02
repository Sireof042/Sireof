#include "board.hpp"
#include <iostream>

using namespace std;

void displayBoard(const vector<vector<char>>& board) {
    cout << "\n";
    for (const auto& row : board) {
        for (char cell : row) {
            cout << " " << cell << " ";
        }
        cout << "\n";
    }
}

bool isValidMove(const vector<vector<char>>& board, int row, int col) {
    return row >= 0 && row < board.size() &&
           col >= 0 && col < board.size() &&
           board[row][col] == ' ';
}
