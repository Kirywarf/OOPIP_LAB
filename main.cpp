#include <iostream>
#include <clocale>
#ifdef _WIN32
#include <windows.h>
#endif

#include "Lab1.h"
#include "Lab2.h"
#include "Lab3.h"
#include "Lab4.h"
#include "Lab5.h"
#include "Lab6.h"
#include "Lab7.h"
#include "Lab8.h"
#include "Lab9.h"

using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
#endif
    setlocale(LC_ALL, ".UTF8");

    int choice;
    do {
        cout << "\n========== OOPiP_LABS ==========\n";
        cout << "1. Лабораторная 1 - String\n";
        cout << "2. Лабораторная 2 - Pair / friend / operators\n";
        cout << "3. Лабораторная 3 - Faculty / inheritance\n";
        cout << "4. Лабораторная 4 - MobileApp / polymorphism\n";
        cout << "5. Лабораторная 5 - СТО / UML\n";
        cout << "6. Лабораторная 6 - MobileApp / arrays / search\n";
        cout << "7. Лабораторная 7 - Game development / templates\n";
        cout << "8. Лабораторная 8 - Smart pointers / transactions\n";
        cout << "9. Лабораторная 9 - Exceptions / mobile catalog\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        cin >> choice;
        cin.ignore(1000, '\n');

        switch (choice) {
        case 1: runLab1(); break;
        case 2: runLab2(); break;
        case 3: runLab3(); break;
        case 4: runLab4(); break;
        case 5: runLab5(); break;
        case 6: runLab6(); break;
        case 7: runLab7(); break;
        case 8: runLab8(); break;
        case 9: runLab9(); break;
        case 0: cout << "Завершение программы.\n"; break;
        default: cout << "Неверный пункт меню.\n";
        }
    } while (choice != 0);

    return 0;
}