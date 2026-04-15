#include "Lab3.h"
#include "Utils.h"
#include <iostream>

using namespace std;

// Faculty
Faculty::Faculty() : facultyName(""), foundationYear(0), specialties("") {}
Faculty::Faculty(const string& name, int year, const string& spec)
    : facultyName(name), foundationYear(year), specialties(spec) {
}
Faculty::Faculty(const Faculty& other)
    : facultyName(other.facultyName), foundationYear(other.foundationYear), specialties(other.specialties) {
}

Faculty& Faculty::operator=(const Faculty& other) {
    if (this != &other) {
        facultyName = other.facultyName;
        foundationYear = other.foundationYear;
        specialties = other.specialties;
    }
    return *this;
}

Faculty::~Faculty() {}

void Faculty::setFacultyName(const string& name) { facultyName = name; }
void Faculty::setFoundationYear(int year) { if (year > 1800 && year <= 2100) foundationYear = year; }
void Faculty::setSpecialties(const string& spec) { specialties = spec; }

string Faculty::getFacultyName() const { return facultyName; }
int Faculty::getFoundationYear() const { return foundationYear; }
string Faculty::getSpecialties() const { return specialties; }

void Faculty::input() {
    facultyName = inputLine("Введите название факультета: ");
    foundationYear = inputInt("Введите год создания факультета: ");
    specialties = inputLine("Введите выпускаемые специальности: ");
}

void Faculty::print() const {
    cout << "Факультет: " << facultyName << endl;
    cout << "Год создания: " << foundationYear << endl;
    cout << "Специальности: " << specialties << endl;
}

double Faculty::getAverageScore() const { return 0.0; }
string Faculty::getStudyForm() const { return "Faculty"; }

// FullTimeStudent
FullTimeStudent::FullTimeStudent()
    : Faculty(), fullName(""), birthYear(0), session1(0), session2(0), scholarship(0) {
}

FullTimeStudent::FullTimeStudent(const string& faculty, int year, const string& spec,
    const string& name, int birth,
    double s1, double s2, double st)
    : Faculty(faculty, year, spec),
    fullName(name), birthYear(birth), session1(s1), session2(s2), scholarship(st) {
}

FullTimeStudent::FullTimeStudent(const FullTimeStudent& other)
    : Faculty(other), fullName(other.fullName), birthYear(other.birthYear),
    session1(other.session1), session2(other.session2), scholarship(other.scholarship) {
}

FullTimeStudent& FullTimeStudent::operator=(const FullTimeStudent& other) {
    if (this != &other) {
        Faculty::operator=(other);
        fullName = other.fullName;
        birthYear = other.birthYear;
        session1 = other.session1;
        session2 = other.session2;
        scholarship = other.scholarship;
    }
    return *this;
}

FullTimeStudent::~FullTimeStudent() {}

void FullTimeStudent::setFullName(const string& name) { fullName = name; }
void FullTimeStudent::setBirthYear(int year) { if (year > 1900 && year <= 2100) birthYear = year; }
void FullTimeStudent::setSession1(double value) { if (value >= 0 && value <= 10) session1 = value; }
void FullTimeStudent::setSession2(double value) { if (value >= 0 && value <= 10) session2 = value; }
void FullTimeStudent::setScholarship(double value) { if (value >= 0) scholarship = value; }

string FullTimeStudent::getFullName() const { return fullName; }
int FullTimeStudent::getBirthYear() const { return birthYear; }
double FullTimeStudent::getSession1() const { return session1; }
double FullTimeStudent::getSession2() const { return session2; }
double FullTimeStudent::getScholarship() const { return scholarship; }

void FullTimeStudent::input() {
    Faculty::input();
    fullName = inputLine("Введите ФИО студента дневной формы: ");
    birthYear = inputInt("Введите год рождения: ");
    session1 = inputDouble("Введите результат 1-й сессии: ");
    session2 = inputDouble("Введите результат 2-й сессии: ");
    scholarship = inputDouble("Введите размер стипендии: ");
}

void FullTimeStudent::print() const {
    Faculty::print();
    cout << "ФИО: " << fullName << endl;
    cout << "Год рождения: " << birthYear << endl;
    cout << "Результат 1-й сессии: " << session1 << endl;
    cout << "Результат 2-й сессии: " << session2 << endl;
    cout << "Стипендия: " << scholarship << endl;
    cout << "Форма обучения: Дневная" << endl;
    cout << "Средний балл: " << getAverageScore() << endl;
}

double FullTimeStudent::getAverageScore() const { return (session1 + session2) / 2.0; }
string FullTimeStudent::getStudyForm() const { return "Дневная"; }

// DistanceStudent
DistanceStudent::DistanceStudent()
    : Faculty(), fullName(""), birthYear(0), session1(0), session2(0), scholarship(0) {
}

DistanceStudent::DistanceStudent(const string& faculty, int year, const string& spec,
    const string& name, int birth,
    double s1, double s2, double st)
    : Faculty(faculty, year, spec),
    fullName(name), birthYear(birth), session1(s1), session2(s2), scholarship(st) {
}

DistanceStudent::DistanceStudent(const DistanceStudent& other)
    : Faculty(other), fullName(other.fullName), birthYear(other.birthYear),
    session1(other.session1), session2(other.session2), scholarship(other.scholarship) {
}

DistanceStudent& DistanceStudent::operator=(const DistanceStudent& other) {
    if (this != &other) {
        Faculty::operator=(other);
        fullName = other.fullName;
        birthYear = other.birthYear;
        session1 = other.session1;
        session2 = other.session2;
        scholarship = other.scholarship;
    }
    return *this;
}

DistanceStudent::~DistanceStudent() {}

void DistanceStudent::setFullName(const string& name) { fullName = name; }
void DistanceStudent::setBirthYear(int year) { if (year > 1900 && year <= 2100) birthYear = year; }
void DistanceStudent::setSession1(double value) { if (value >= 0 && value <= 10) session1 = value; }
void DistanceStudent::setSession2(double value) { if (value >= 0 && value <= 10) session2 = value; }
void DistanceStudent::setScholarship(double value) { if (value >= 0) scholarship = value; }

string DistanceStudent::getFullName() const { return fullName; }
int DistanceStudent::getBirthYear() const { return birthYear; }
double DistanceStudent::getSession1() const { return session1; }
double DistanceStudent::getSession2() const { return session2; }
double DistanceStudent::getScholarship() const { return scholarship; }

void DistanceStudent::input() {
    Faculty::input();
    fullName = inputLine("Введите ФИО студента дистанционной формы: ");
    birthYear = inputInt("Введите год рождения: ");
    session1 = inputDouble("Введите результат 1-й сессии: ");
    session2 = inputDouble("Введите результат 2-й сессии: ");
    scholarship = inputDouble("Введите размер стипендии: ");
}

void DistanceStudent::print() const {
    Faculty::print();
    cout << "ФИО: " << fullName << endl;
    cout << "Год рождения: " << birthYear << endl;
    cout << "Результат 1-й сессии: " << session1 << endl;
    cout << "Результат 2-й сессии: " << session2 << endl;
    cout << "Стипендия: " << scholarship << endl;
    cout << "Форма обучения: Дистанционная" << endl;
    cout << "Средний балл: " << getAverageScore() << endl;
}

double DistanceStudent::getAverageScore() const { return (session1 + session2) / 2.0; }
string DistanceStudent::getStudyForm() const { return "Дистанционная"; }

void runLab3() {
    cout << "\n===== ЛАБОРАТОРНАЯ РАБОТА 3 =====\n";

    int n = inputInt("Введите количество студентов: ");
    if (n <= 0) {
        cout << "Количество должно быть больше 0.\n";
        return;
    }

    Faculty** arr = new Faculty * [n];

    for (int i = 0; i < n; i++) {
        cout << "\nСтудент #" << i + 1 << endl;
        cout << "1 - Студент дневной формы\n";
        cout << "2 - Студент дистанционной формы\n";
        int type = inputInt("Выбор: ");

        if (type == 1) arr[i] = new FullTimeStudent();
        else arr[i] = new DistanceStudent();

        arr[i]->input();
    }

    cout << "\n===== Все введённые данные =====\n";
    for (int i = 0; i < n; i++) {
        arr[i]->print();
        cout << "-----------------------------\n";
    }

    double fullSum = 0.0, distSum = 0.0;
    int fullCount = 0, distCount = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i]->getStudyForm() == "Дневная") {
            fullSum += arr[i]->getAverageScore();
            fullCount++;
        }
        else {
            distSum += arr[i]->getAverageScore();
            distCount++;
        }
    }

    cout << "\n===== Успеваемость по формам обучения =====\n";
    if (fullCount > 0) cout << "Средний балл дневной формы: " << fullSum / fullCount << endl;
    else cout << "Студенты дневной формы отсутствуют.\n";

    if (distCount > 0) cout << "Средний балл дистанционной формы: " << distSum / distCount << endl;
    else cout << "Студенты дистанционной формы отсутствуют.\n";

    for (int i = 0; i < n; i++) delete arr[i];
    delete[] arr;

    pressEnter();
}