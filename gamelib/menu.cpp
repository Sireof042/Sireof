#include <iostream>
#include "game.hpp"
#include "params.hpp"
#include "history.hpp"

using namespace std;

void showMenu() {
    char choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Start Game\n";
        cout << "2. Settings\n";
        cout << "3. Game History\n";
        cout << "4. Exit\n";
        cout << "Select an option (1-4): ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case '1': startGame(); break;
            case '2': setParameters(); break;
            case '3': loadHistory(); break;
            case '4': cout << "Exiting program.\n"; break;
            default: cout << "Invalid input, please try again.\n";
        }
    } while (choice != '4');
}
