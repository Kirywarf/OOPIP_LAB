#include "Lab6.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

AppRecord::AppRecord() : appName(""), version(""), creationDate(""), operatingSystem(""), sizeMB(0), developer("") {}

AppRecord::AppRecord(const string& name, const string& ver,
    const string& date, const string& os,
    double size, const string& dev)
    : appName(name), version(ver), creationDate(date), operatingSystem(os), sizeMB(size), developer(dev) {
}

AppRecord::AppRecord(const AppRecord& other)
    : appName(other.appName), version(other.version), creationDate(other.creationDate),
    operatingSystem(other.operatingSystem), sizeMB(other.sizeMB), developer(other.developer) {
}

AppRecord& AppRecord::operator=(const AppRecord& other) {
    if (this != &other) {
        appName = other.appName;
        version = other.version;
        creationDate = other.creationDate;
        operatingSystem = other.operatingSystem;
        sizeMB = other.sizeMB;
        developer = other.developer;
    }
    return *this;
}

AppRecord::~AppRecord() {}

void AppRecord::setAppName(const string& name) { appName = name; }
void AppRecord::setVersion(const string& ver) { version = ver; }
void AppRecord::setCreationDate(const string& date) { creationDate = date; }
void AppRecord::setOperatingSystem(const string& os) { operatingSystem = os; }
void AppRecord::setSizeMB(double size) { if (size >= 0) sizeMB = size; }
void AppRecord::setDeveloper(const string& dev) { developer = dev; }

string AppRecord::getAppName() const { return appName; }
string AppRecord::getVersion() const { return version; }
string AppRecord::getCreationDate() const { return creationDate; }
string AppRecord::getOperatingSystem() const { return operatingSystem; }
double AppRecord::getSizeMB() const { return sizeMB; }
string AppRecord::getDeveloper() const { return developer; }

void AppRecord::input() {
    appName = inputLine("Введите название приложения: ");
    version = inputLine("Введите версию: ");
    creationDate = inputLine("Введите дату создания (дд.мм.гггг): ");
    operatingSystem = inputLine("Введите ОС: ");
    sizeMB = inputDouble("Введите размер в МБ: ");
    developer = inputLine("Введите разработчика: ");
}

void AppRecord::print() const {
    cout << "Название: " << appName << endl;
    cout << "Версия: " << version << endl;
    cout << "Дата создания: " << creationDate << endl;
    cout << "ОС: " << operatingSystem << endl;
    cout << "Размер: " << sizeMB << " МБ" << endl;
    cout << "Разработчик: " << developer << endl;
}

void AppRecord::saveToFile(const string& filename) const {
    ofstream fout(filename, ios::app);
    if (fout.is_open()) {
        fout << "Название: " << appName << endl;
        fout << "Версия: " << version << endl;
        fout << "Дата создания: " << creationDate << endl;
        fout << "ОС: " << operatingSystem << endl;
        fout << "Размер: " << sizeMB << " МБ" << endl;
        fout << "Разработчик: " << developer << endl;
        fout << "-----------------------------" << endl;
        fout.close();
    }
}

int AppRecord::getYear() const {
    if (creationDate.length() >= 4) {
        return atoi(creationDate.substr(creationDate.length() - 4, 4).c_str());
    }
    return 0;
}

bool AppRecord::matchesOS(const string& os) const { return operatingSystem == os; }
bool AppRecord::matchesYear(int year) const { return getYear() == year; }

void runLab6() {
    cout << "\n===== ЛАБОРАТОРНАЯ РАБОТА 6 =====\n";

    int n = inputInt("Введите количество приложений: ");
    if (n <= 0) return;

    AppRecord* arr = new AppRecord[n];

    for (int i = 0; i < n; i++) {
        cout << "\nПриложение #" << i + 1 << endl;
        arr[i].input();
    }

    cout << "\n===== Все приложения =====\n";
    for (int i = 0; i < n; i++) {
        arr[i].print();
        cout << "-----------------------------\n";
    }

    ofstream clearAll("lab6_all.txt");
    clearAll.close();
    for (int i = 0; i < n; i++) arr[i].saveToFile("lab6_all.txt");

    string os = inputLine("Введите ОС для поиска: ");
    ofstream clearOS("lab6_search_os.txt");
    clearOS.close();

    cout << "\nПриложения для ОС " << os << ":\n";
    bool foundOS = false;
    for (int i = 0; i < n; i++) {
        if (arr[i].matchesOS(os)) {
            arr[i].print();
            cout << "-----------------------------\n";
            arr[i].saveToFile("lab6_search_os.txt");
            foundOS = true;
        }
    }
    if (!foundOS) cout << "Ничего не найдено.\n";

    int year = inputInt("Введите год выпуска для поиска: ");
    ofstream clearYear("lab6_search_year.txt");
    clearYear.close();

    cout << "\nПриложения за " << year << " год:\n";
    bool foundYear = false;
    for (int i = 0; i < n; i++) {
        if (arr[i].matchesYear(year)) {
            arr[i].print();
            cout << "-----------------------------\n";
            arr[i].saveToFile("lab6_search_year.txt");
            foundYear = true;
        }
    }
    if (!foundYear) cout << "Ничего не найдено.\n";

    delete[] arr;
    pressEnter();
}