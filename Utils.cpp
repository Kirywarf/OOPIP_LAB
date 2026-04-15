#include "Utils.h"
#include <iostream>
#include <limits>

using namespace std;

string inputLine(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

int inputInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода. Повторите.\n";
    }
}

double inputDouble(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка ввода. Повторите.\n";
    }
}

void pressEnter() {
    cout << "\nНажмите Enter для продолжения...";
    cin.get();
}