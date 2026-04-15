#include "Lab1.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int MyString::counter = 0;

MyString::MyString() : data(""), id(++counter) {}
MyString::MyString(const string& s) : data(s), id(++counter) {}
MyString::MyString(const MyString& other) : data(other.data), id(++counter) {}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

MyString::~MyString() {}

void MyString::setData(const string& s) { data = s; }
string MyString::getData() const { return data; }
int MyString::getId() const { return id; }
int MyString::getCounter() { return counter; }
int MyString::length() const { return static_cast<int>(data.length()); }
bool MyString::isEmpty() const { return data.empty(); }

void MyString::ltrim() {
    int i = 0;
    while (i < static_cast<int>(data.length()) &&
        isspace(static_cast<unsigned char>(data[i]))) {
        i++;
    }
    data.erase(0, i);
}

void MyString::rtrim() {
    if (data.empty()) return;
    int i = static_cast<int>(data.length()) - 1;
    while (i >= 0 && isspace(static_cast<unsigned char>(data[i]))) {
        i--;
    }
    data.erase(i + 1);
}

void MyString::trim() {
    ltrim();
    rtrim();
}

MyString MyString::concat(const MyString& other) const {
    return MyString(data + other.data);
}

MyString MyString::concat_ws(const string& sep, const MyString& other) const {
    return MyString(data + sep + other.data);
}

void MyString::print() const {
    cout << "ID: " << id << " | \"" << data << "\" | length = " << length() << endl;
}

void MyString::saveToFile(const string& filename) const {
    ofstream fout(filename);
    if (fout.is_open()) {
        fout << data;
        fout.close();
    }
}

void runLab1() {
    cout << "\n===== ЛАБОРАТОРНАЯ РАБОТА 1 =====\n";

    int n = inputInt("Введите количество строк: ");
    if (n <= 0) {
        cout << "Количество должно быть больше 0.\n";
        return;
    }

    MyString* arr = new MyString[n];

    for (int i = 0; i < n; i++) {
        arr[i].setData(inputLine("Введите строку " + to_string(i + 1) + ": "));
    }

    cout << "\nВсе строки:\n";
    for (int i = 0; i < n; i++) {
        arr[i].print();
    }

    MyString concatResult = arr[0];
    for (int i = 1; i < n; i++) {
        concatResult = concatResult.concat(arr[i]);
    }

    cout << "\nРезультат concat:\n";
    concatResult.print();

    MyString concatWsResult = arr[0];
    for (int i = 1; i < n; i++) {
        concatWsResult = concatWsResult.concat_ws(" ", arr[i]);
    }

    cout << "\nРезультат concat_ws:\n";
    concatWsResult.print();

    cout << "\nTrim первой строки:\n";
    arr[0].trim();
    arr[0].print();

    concatWsResult.saveToFile("lab1_output.txt");
    cout << "\nРезультат сохранён в lab1_output.txt\n";

    delete[] arr;
    pressEnter();
}