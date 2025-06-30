#include "history.hpp"
#include <iostream>
#include <fstream>

using namespace std;

const string HISTORY_FILE = "history.txt";

void loadHistory() {
    ifstream file(HISTORY_FILE);
    if (file) {
        string line;
        cout << "\nGame History:\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
    } else {
        cout << "\nGame history is empty.\n";
    }
    cout << "Press Enter to return to the menu...";
    cin.ignore();
}

void saveHistory(const string& record) {
    ofstream file(HISTORY_FILE, ios::app);
    file << record << endl;
}
