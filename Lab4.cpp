#include "Lab4.h"
#include "Utils.h"

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

MobileApp::MobileApp()
    : appName(""), version(""), creationDate(""), operatingSystem(""), sizeMB(0.0), developer("") {}

MobileApp::MobileApp(const string& name, const string& ver, const string& date,
    const string& os, double size, const string& dev)
    : appName(name), version(ver), creationDate(date), operatingSystem(os), sizeMB(size), developer(dev) {}

MobileApp::MobileApp(const MobileApp& other)
    : appName(other.appName), version(other.version), creationDate(other.creationDate),
      operatingSystem(other.operatingSystem), sizeMB(other.sizeMB), developer(other.developer) {}

MobileApp& MobileApp::operator=(const MobileApp& other) {
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

MobileApp::~MobileApp() {}

void MobileApp::setAppName(const string& name) { appName = name; }
void MobileApp::setVersion(const string& ver) { version = ver; }
void MobileApp::setCreationDate(const string& date) { creationDate = date; }
void MobileApp::setOperatingSystem(const string& os) { operatingSystem = os; }
void MobileApp::setSizeMB(double size) { if (size >= 0) sizeMB = size; }
void MobileApp::setDeveloper(const string& dev) { developer = dev; }

string MobileApp::getAppName() const { return appName; }
string MobileApp::getVersion() const { return version; }
string MobileApp::getCreationDate() const { return creationDate; }
string MobileApp::getOperatingSystem() const { return operatingSystem; }
double MobileApp::getSizeMB() const { return sizeMB; }
string MobileApp::getDeveloper() const { return developer; }

void MobileApp::input() {
    appName = inputLine("Введите название приложения: ");
    version = inputLine("Введите версию: ");
    creationDate = inputLine("Введите дату создания (дд.мм.гггг): ");
    operatingSystem = inputLine("Введите ОС: ");
    sizeMB = inputDouble("Введите размер в МБ: ");
    developer = inputLine("Введите разработчика: ");
}

void MobileApp::print() const {
    cout << "Тип: " << getType() << endl;
    cout << "Название: " << appName << endl;
    cout << "Версия: " << version << endl;
    cout << "Дата создания: " << creationDate << endl;
    cout << "ОС: " << operatingSystem << endl;
    cout << "Размер: " << sizeMB << " МБ" << endl;
    cout << "Разработчик: " << developer << endl;
}

void MobileApp::saveToFile(ofstream& fout) const {
    fout << "Тип: " << getType() << endl;
    fout << "Название: " << appName << endl;
    fout << "Версия: " << version << endl;
    fout << "Дата создания: " << creationDate << endl;
    fout << "ОС: " << operatingSystem << endl;
    fout << "Размер: " << sizeMB << " МБ" << endl;
    fout << "Разработчик: " << developer << endl;
}

string MobileApp::getType() const {
    return "Обычное приложение";
}

bool MobileApp::matchesOS(const string& os) const {
    return operatingSystem == os;
}

int MobileApp::extractYear() const {
    if (creationDate.length() >= 4) {
        return atoi(creationDate.substr(creationDate.length() - 4, 4).c_str());
    }
    return 0;
}

bool MobileApp::matchesYear(int year) const {
    return extractYear() == year;
}

GameApp::GameApp() : MobileApp(), genre(""), ageLimit(0) {}

GameApp::GameApp(const string& name, const string& ver, const string& date,
    const string& os, double size, const string& dev,
    const string& g, int age)
    : MobileApp(name, ver, date, os, size, dev), genre(g), ageLimit(age) {}

GameApp::GameApp(const GameApp& other)
    : MobileApp(other), genre(other.genre), ageLimit(other.ageLimit) {}

GameApp& GameApp::operator=(const GameApp& other) {
    if (this != &other) {
        MobileApp::operator=(other);
        genre = other.genre;
        ageLimit = other.ageLimit;
    }
    return *this;
}

GameApp::~GameApp() {}

void GameApp::setGenre(const string& g) { genre = g; }
void GameApp::setAgeLimit(int age) { if (age >= 0) ageLimit = age; }
string GameApp::getGenre() const { return genre; }
int GameApp::getAgeLimit() const { return ageLimit; }

void GameApp::input() {
    MobileApp::input();
    genre = inputLine("Введите жанр игры: ");
    ageLimit = inputInt("Введите возрастное ограничение: ");
}

void GameApp::print() const {
    MobileApp::print();
    cout << "Жанр: " << genre << endl;
    cout << "Возрастное ограничение: " << ageLimit << "+" << endl;
}

void GameApp::saveToFile(ofstream& fout) const {
    MobileApp::saveToFile(fout);
    fout << "Жанр: " << genre << endl;
    fout << "Возрастное ограничение: " << ageLimit << "+" << endl;
}

string GameApp::getType() const {
    return "Игра";
}

BusinessApp::BusinessApp() : MobileApp(), category(""), cloudSync(false) {}

BusinessApp::BusinessApp(const string& name, const string& ver, const string& date,
    const string& os, double size, const string& dev,
    const string& cat, bool sync)
    : MobileApp(name, ver, date, os, size, dev), category(cat), cloudSync(sync) {}

BusinessApp::BusinessApp(const BusinessApp& other)
    : MobileApp(other), category(other.category), cloudSync(other.cloudSync) {}

BusinessApp& BusinessApp::operator=(const BusinessApp& other) {
    if (this != &other) {
        MobileApp::operator=(other);
        category = other.category;
        cloudSync = other.cloudSync;
    }
    return *this;
}

BusinessApp::~BusinessApp() {}

void BusinessApp::setCategory(const string& cat) { category = cat; }
void BusinessApp::setCloudSync(bool sync) { cloudSync = sync; }
string BusinessApp::getCategory() const { return category; }
bool BusinessApp::getCloudSync() const { return cloudSync; }

void BusinessApp::input() {
    MobileApp::input();
    category = inputLine("Введите категорию бизнес-приложения: ");
    int sync = inputInt("Нужна облачная синхронизация? (1 - да, 0 - нет): ");
    cloudSync = (sync != 0);
}

void BusinessApp::print() const {
    MobileApp::print();
    cout << "Категория: " << category << endl;
    cout << "Облачная синхронизация: " << (cloudSync ? "Да" : "Нет") << endl;
}

void BusinessApp::saveToFile(ofstream& fout) const {
    MobileApp::saveToFile(fout);
    fout << "Категория: " << category << endl;
    fout << "Облачная синхронизация: " << (cloudSync ? "Да" : "Нет") << endl;
}

string BusinessApp::getType() const {
    return "Бизнес-приложение";
}

void runLab4() {
    cout << "\n===== ЛАБОРАТОРНАЯ РАБОТА 4 =====\n";

    int n = inputInt("Введите количество приложений: ");
    if (n <= 0) {
        cout << "Количество должно быть больше 0.\n";
        return;
    }

    MobileApp** apps = new MobileApp*[n];

    for (int i = 0; i < n; ++i) {
        cout << "\nПриложение #" << i + 1 << "\n";
        int type;
        do {
            type = inputInt("Тип (1 - игра, 2 - бизнес): ");
            if (type != 1 && type != 2) {
                cout << "Некорректный тип. Введите 1 или 2.\n";
            }
        } while (type != 1 && type != 2);

        apps[i] = (type == 1) ? static_cast<MobileApp*>(new GameApp())
                              : static_cast<MobileApp*>(new BusinessApp());

        apps[i]->input();
    }

    ofstream clearAll("lab4_all.txt");
    clearAll.close();
    ofstream foutAll("lab4_all.txt", ios::app);
    if (!foutAll.is_open()) {
        cout << "Ошибка открытия файла lab4_all.txt\n";
        for (int i = 0; i < n; ++i) delete apps[i];
        delete[] apps;
        pressEnter();
        return;
    }

    cout << "\n===== Все приложения =====\n";
    for (int i = 0; i < n; ++i) {
        apps[i]->print();
        cout << "-----------------------------\n";
        apps[i]->saveToFile(foutAll);
        foutAll << "-----------------------------\n";
    }
    foutAll.close();

    string os = inputLine("Введите ОС для поиска: ");
    ofstream foutOS("lab4_search_os.txt");
    if (!foutOS.is_open()) {
        cout << "Ошибка открытия файла lab4_search_os.txt\n";
        for (int i = 0; i < n; ++i) delete apps[i];
        delete[] apps;
        pressEnter();
        return;
    }

    bool foundOS = false;
    cout << "\nПриложения для ОС " << os << ":\n";
    for (int i = 0; i < n; ++i) {
        if (apps[i]->matchesOS(os)) {
            apps[i]->print();
            cout << "-----------------------------\n";
            apps[i]->saveToFile(foutOS);
            foutOS << "-----------------------------\n";
            foundOS = true;
        }
    }
    if (!foundOS) cout << "Ничего не найдено.\n";
    foutOS.close();

    int year = inputInt("Введите год выпуска для поиска: ");
    ofstream foutYear("lab4_search_year.txt");
    if (!foutYear.is_open()) {
        cout << "Ошибка открытия файла lab4_search_year.txt\n";
        for (int i = 0; i < n; ++i) delete apps[i];
        delete[] apps;
        pressEnter();
        return;
    }

    bool foundYear = false;
    cout << "\nПриложения за " << year << " год:\n";
    for (int i = 0; i < n; ++i) {
        if (apps[i]->matchesYear(year)) {
            apps[i]->print();
            cout << "-----------------------------\n";
            apps[i]->saveToFile(foutYear);
            foutYear << "-----------------------------\n";
            foundYear = true;
        }
    }
    if (!foundYear) cout << "Ничего не найдено.\n";
    foutYear.close();

    for (int i = 0; i < n; ++i) {
        delete apps[i];
    }
    delete[] apps;

    pressEnter();
}
