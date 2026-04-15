#include "Lab2.h"
#include "Utils.h"
#include <iostream>

using namespace std;

Pair::Pair() : key(""), value("") {}
Pair::Pair(const string& k, const string& v) : key(k), value(v) {}
Pair::Pair(const Pair& other) : key(other.key), value(other.value) {}

Pair& Pair::operator=(const Pair& other) {
    if (this != &other) {
        key = other.key;
        value = other.value;
    }
    return *this;
}

Pair::~Pair() {}

void Pair::setKey(const string& k) { key = k; }
void Pair::setValue(const string& v) { value = v; }

string Pair::getKey() const { return key; }
string Pair::getValue() const { return value; }

bool Pair::operator<(const Pair& other) const {
    if (key < other.key) return true;
    if (key == other.key && value < other.value) return true;
    return false;
}

bool Pair::operator>(const Pair& other) const {
    if (key > other.key) return true;
    if (key == other.key && value > other.value) return true;
    return false;
}

bool Pair::operator==(const Pair& other) const {
    return key == other.key && value == other.value;
}

bool Pair::operator!=(const Pair& other) const {
    return !(*this == other);
}

ostream& operator<<(ostream& out, const Pair& p) {
    out << "Ключ: " << p.key << " | Значение: " << p.value;
    return out;
}

istream& operator>>(istream& in, Pair& p) {
    cout << "Введите ключ: ";
    getline(in, p.key);
    cout << "Введите значение: ";
    getline(in, p.value);
    return in;
}

void runLab2() {
    cout << "\n===== ЛАБОРАТОРНАЯ РАБОТА 2 =====\n";

    int n = inputInt("Введите количество объектов Pair: ");
    if (n <= 0) {
        cout << "Количество должно быть больше 0.\n";
        return;
    }

    Pair* arr = new Pair[n];

    for (int i = 0; i < n; i++) {
        cout << "\nПара #" << i + 1 << endl;
        cin >> arr[i];
    }

    cout << "\nВсе пары:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ") " << arr[i] << endl;
    }

    int a = inputInt("\nВведите номер первой пары: ");
    int b = inputInt("Введите номер второй пары: ");

    if (a >= 1 && a <= n && b >= 1 && b <= n) {
        cout << "\nПервая пара: " << arr[a - 1] << endl;
        cout << "Вторая пара: " << arr[b - 1] << endl;

        cout << "\nРезультаты сравнения:\n";
        cout << "Первая < Вторая  : " << (arr[a - 1] < arr[b - 1] ? "true" : "false") << endl;
        cout << "Первая > Вторая  : " << (arr[a - 1] > arr[b - 1] ? "true" : "false") << endl;
        cout << "Первая == Вторая : " << (arr[a - 1] == arr[b - 1] ? "true" : "false") << endl;
        cout << "Первая != Вторая : " << (arr[a - 1] != arr[b - 1] ? "true" : "false") << endl;
    }
    else {
        cout << "Неверные номера.\n";
    }

    delete[] arr;
    pressEnter();
}