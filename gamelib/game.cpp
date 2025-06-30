#include "game.hpp"
#include "board.hpp"
#include "params.hpp"
#include "history.hpp"
#include <iostream>
#include <vector>

using namespace std;

void startGame() {
    GameParams params = loadParams();
    vector<vector<char>> board(params.size, vector<char>(params.size, ' '));
    char players[] = {'X', 'O'};
    int currentPlayer = 0;
    string currentPlayerName = params.player1;

    cout << "Who will go first? (1) " << params.player1 << " or (2) " << params.player2 << ": ";
    int choice;
    cin >> choice;
    if (choice == 2) {
        currentPlayer = 1;
        currentPlayerName = params.player2;
    }

    int moves = 0;
    while (moves < params.size * params.size) {
        displayBoard(board);
        int row, col;
        do {
            cout << currentPlayerName << " (" << players[currentPlayer] << ") enter row and column: ";
            cin >> row >> col;
        } while (!isValidMove(board, row - 1, col - 1));

        board[row - 1][col - 1] = players[currentPlayer];
        moves++;

        currentPlayer = 1 - currentPlayer;
        currentPlayerName = (currentPlayer == 0) ? params.player1 : params.player2;
    }

    displayBoard(board);
    cout << "Game over! Press Enter to return to the menu...";
    cin.ignore();
    cin.get();
}
