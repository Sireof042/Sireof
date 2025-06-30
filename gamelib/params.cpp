#include "params.hpp"
#include <iostream>
#include <fstream>

using namespace std;

const string PARAMS_FILE = "params.txt";

GameParams loadParams() {
    GameParams params = {3, "User1", "User2"};
    ifstream file(PARAMS_FILE);
    if (file) {
        file >> params.size;
        file.ignore();
        getline(file, params.player1);
        getline(file, params.player2);
    }
    return params;
}

void saveParams(const GameParams& params) {
    ofstream file(PARAMS_FILE);
    file << params.size << endl << params.player1 << endl << params.player2 << endl;
}

void setParameters() {
    GameParams params = loadParams();
    cout << "\nCurrent Settings:\n";
    cout << "Board Size: " << params.size << "x" << params.size << endl;
    cout << "Player 1: " << params.player1 << endl;
    cout << "Player 2: " << params.player2 << endl;

    int newSize;
    do {
        cout << "\nEnter new board size (minimum 3): ";
        cin >> newSize;
    } while (newSize < 3);
    cin.ignore();

    cout << "Enter Player 1 name: ";
    getline(cin, params.player1);
    cout << "Enter Player 2 name: ";
    getline(cin, params.player2);

    saveParams(params);
    cout << "\nSettings saved. Press Enter to return to the menu...";
    cin.ignore();
}
