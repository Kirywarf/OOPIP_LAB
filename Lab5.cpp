#include "Lab5.h"
#include "Utils.h"
#include <iostream>

using namespace std;

static int chooseIndex(const string& prompt, int count) {
    int index;
    do {
        index = inputInt(prompt);
        if (index < 0 || index >= count) {
            cout << "Неверный индекс. Повторите.\n";
        }
    } while (index < 0 || index >= count);
    return index;
}

// ==================== CarModel ====================

CarModel::CarModel() : title("") {}
CarModel::CarModel(const string& t) : title(t) {}
CarModel::CarModel(const CarModel& other) : title(other.title) {}
CarModel::~CarModel() {}

void CarModel::setTitle(const string& t) { title = t; }
string CarModel::getTitle() const { return title; }

void CarModel::input() {
    title = inputLine("Введите название модели автомобиля: ");
}

void CarModel::print() const {
    cout << "CarModel: " << title << endl;
}

// ==================== GearBoxType ====================

GearBoxType::GearBoxType() : name(""), remarks("") {}
GearBoxType::GearBoxType(const string& n, const string& r) : name(n), remarks(r) {}
GearBoxType::GearBoxType(const GearBoxType& other) : name(other.name), remarks(other.remarks) {}
GearBoxType::~GearBoxType() {}

void GearBoxType::setName(const string& n) { name = n; }
void GearBoxType::setRemarks(const string& r) { remarks = r; }

string GearBoxType::getName() const { return name; }
string GearBoxType::getRemarks() const { return remarks; }

void GearBoxType::input() {
    name = inputLine("Введите тип коробки передач: ");
    remarks = inputLine("Введите примечание: ");
}

void GearBoxType::print() const {
    cout << "GearBoxType: " << name << ", remarks: " << remarks << endl;
}

// ==================== GearBox ====================

GearBox::GearBox() : type(), gearCount(0), currentGear(0) {
    for (int i = 0; i < MAX_GEARS; i++) gearRatio[i] = 0.0f;
}

GearBox::GearBox(const GearBoxType& t, const float ratios[], int count, int current)
    : type(t), gearCount(0), currentGear(0) {
    for (int i = 0; i < MAX_GEARS; i++) gearRatio[i] = 0.0f;
    setRatios(ratios, count);
    setCurrentGear(current);
}

GearBox::GearBox(const GearBox& other)
    : type(other.type), gearCount(other.gearCount), currentGear(other.currentGear) {
    for (int i = 0; i < MAX_GEARS; i++) {
        gearRatio[i] = other.gearRatio[i];
    }
}

GearBox::~GearBox() {}

void GearBox::setType(const GearBoxType& t) {
    type = t;
}

void GearBox::setRatios(const float ratios[], int count) {
    if (count < 1) count = 1;
    if (count > MAX_GEARS) count = MAX_GEARS;

    gearCount = count;
    for (int i = 0; i < MAX_GEARS; i++) gearRatio[i] = 0.0f;
    for (int i = 0; i < gearCount; i++) gearRatio[i] = ratios[i];
}

void GearBox::setCurrentGear(int gear) {
    if (gear < 0) gear = 0;
    if (gear > gearCount) gear = gearCount;
    currentGear = gear;
}

GearBoxType GearBox::getType() const { return type; }
int GearBox::getGearCount() const { return gearCount; }
int GearBox::getCurrentGear() const { return currentGear; }

float GearBox::getGearRatio(int index) const {
    if (index >= 0 && index < gearCount) return gearRatio[index];
    return 0.0f;
}

void GearBox::shiftUp() {
    if (currentGear < gearCount) currentGear++;
}

void GearBox::shiftDown() {
    if (currentGear > 0) currentGear--;
}

void GearBox::input() {
    type.input();

    gearCount = inputInt("Введите количество передач (1-6): ");
    if (gearCount < 1) gearCount = 1;
    if (gearCount > MAX_GEARS) gearCount = MAX_GEARS;

    for (int i = 0; i < gearCount; i++) {
        gearRatio[i] = static_cast<float>(inputDouble("Введите передаточное число передачи " + to_string(i + 1) + ": "));
    }

    currentGear = inputInt("Введите текущую передачу: ");
    if (currentGear < 0) currentGear = 0;
    if (currentGear > gearCount) currentGear = gearCount;
}

void GearBox::print() const {
    cout << "GearBox: ";
    type.print();
    cout << "Передаточные числа: ";
    for (int i = 0; i < gearCount; i++) {
        cout << gearRatio[i] << " ";
    }
    cout << "| currentGear = " << currentGear << endl;
}

// ==================== Engine ====================

Engine::Engine() : capacity(0), numberOfCylinders(0) {}
Engine::Engine(float c, int n) : capacity(c), numberOfCylinders(n) {}
Engine::Engine(const Engine& other) : capacity(other.capacity), numberOfCylinders(other.numberOfCylinders) {}
Engine::~Engine() {}

void Engine::setCapacity(float c) {
    if (c > 0) capacity = c;
}

void Engine::setNumberOfCylinders(int n) {
    if (n > 0) numberOfCylinders = n;
}

float Engine::getCapacity() const { return capacity; }
int Engine::getNumberOfCylinders() const { return numberOfCylinders; }

void Engine::start() const {
    cout << "Двигатель запущен.\n";
}

void Engine::brake() const {
    cout << "Двигатель снижает мощность.\n";
}

void Engine::accelerate() const {
    cout << "Двигатель ускоряет автомобиль.\n";
}

void Engine::input() {
    capacity = static_cast<float>(inputDouble("Введите объем двигателя: "));
    numberOfCylinders = inputInt("Введите количество цилиндров: ");
}

void Engine::print() const {
    cout << "Engine: capacity = " << capacity
        << ", numberOfCylinders = " << numberOfCylinders << endl;
}

// ==================== Body ====================

Body::Body() : numberOfDoors(0) {}
Body::Body(int d) : numberOfDoors(d) {}
Body::Body(const Body& other) : numberOfDoors(other.numberOfDoors) {}
Body::~Body() {}

void Body::setNumberOfDoors(int d) {
    if (d > 0) numberOfDoors = d;
}

int Body::getNumberOfDoors() const { return numberOfDoors; }

void Body::input() {
    numberOfDoors = inputInt("Введите количество дверей: ");
}

void Body::print() const {
    cout << "Body: numberOfDoors = " << numberOfDoors << endl;
}

// ==================== Suspension ====================

Suspension::Suspension() : springRate(0) {}
Suspension::Suspension(float s) : springRate(s) {}
Suspension::Suspension(const Suspension& other) : springRate(other.springRate) {}
Suspension::~Suspension() {}

void Suspension::setSpringRate(float s) {
    if (s > 0) springRate = s;
}

float Suspension::getSpringRate() const { return springRate; }

void Suspension::input() {
    springRate = static_cast<float>(inputDouble("Введите коэффициент жесткости подвески: "));
}

void Suspension::print() const {
    cout << "Suspension: springRate = " << springRate << endl;
}

// ==================== Tire ====================

Tire::Tire() : width(0), airPressure(0) {}
Tire::Tire(float w, float a) : width(w), airPressure(a) {}
Tire::Tire(const Tire& other) : width(other.width), airPressure(other.airPressure) {}
Tire::~Tire() {}

void Tire::setWidth(float w) {
    if (w > 0) width = w;
}

void Tire::setAirPressure(float a) {
    if (a > 0) airPressure = a;
}

float Tire::getWidth() const { return width; }
float Tire::getAirPressure() const { return airPressure; }

void Tire::input() {
    width = static_cast<float>(inputDouble("Введите ширину шины: "));
    airPressure = static_cast<float>(inputDouble("Введите давление воздуха: "));
}

void Tire::print() const {
    cout << "Tire: width = " << width
        << ", airPressure = " << airPressure << endl;
}

// ==================== Wheel ====================

Wheel::Wheel() : diameter(0) {}
Wheel::Wheel(float d) : diameter(d) {}
Wheel::Wheel(const Wheel& other) : diameter(other.diameter) {}
Wheel::~Wheel() {}

void Wheel::setDiameter(float d) {
    if (d > 0) diameter = d;
}

float Wheel::getDiameter() const { return diameter; }

void Wheel::input() {
    diameter = static_cast<float>(inputDouble("Введите диаметр колеса: "));
}

void Wheel::print() const {
    cout << "Wheel: diameter = " << diameter << endl;
}

// ==================== Brake ====================

Brake::Brake() : type("") {}
Brake::Brake(const string& t) : type(t) {}
Brake::Brake(const Brake& other) : type(other.type) {}
Brake::~Brake() {}

void Brake::setType(const string& t) { type = t; }
string Brake::getType() const { return type; }

void Brake::apply() const {
    cout << "Тормоз " << type << " применён.\n";
}

void Brake::input() {
    type = inputLine("Введите тип тормоза: ");
}

void Brake::print() const {
    cout << "Brake: type = " << type << endl;
}

// ==================== Car ====================

Car::Car() : registrationNum(""), year(0), licenseNumber(""),
model(), gearBox(), engine(), body() {
    for (int i = 0; i < PARTS_COUNT; i++) {
        suspensions[i] = Suspension();
        wheels[i] = Wheel();
        tires[i] = Tire();
        brakes[i] = Brake();
    }
}

Car::Car(const string& reg, int y, const string& lic,
    const CarModel& m, const GearBox& g, const Engine& e, const Body& b,
    const Suspension s[], const Wheel w[], const Tire t[], const Brake br[])
    : registrationNum(reg), year(y), licenseNumber(lic),
    model(m), gearBox(g), engine(e), body(b) {
    for (int i = 0; i < PARTS_COUNT; i++) {
        suspensions[i] = s[i];
        wheels[i] = w[i];
        tires[i] = t[i];
        brakes[i] = br[i];
    }
}

Car::Car(const Car& other)
    : registrationNum(other.registrationNum), year(other.year), licenseNumber(other.licenseNumber),
    model(other.model), gearBox(other.gearBox), engine(other.engine), body(other.body) {
    for (int i = 0; i < PARTS_COUNT; i++) {
        suspensions[i] = other.suspensions[i];
        wheels[i] = other.wheels[i];
        tires[i] = other.tires[i];
        brakes[i] = other.brakes[i];
    }
}

Car::~Car() {}

void Car::setRegistrationNum(const string& reg) { registrationNum = reg; }
void Car::setYear(int y) { if (y > 1900) year = y; }
void Car::setLicenseNumber(const string& lic) { licenseNumber = lic; }
void Car::setModel(const CarModel& m) { model = m; }
void Car::setGearBox(const GearBox& g) { gearBox = g; }
void Car::setEngine(const Engine& e) { engine = e; }
void Car::setBody(const Body& b) { body = b; }

void Car::setSuspension(int index, const Suspension& s) {
    if (index >= 0 && index < PARTS_COUNT) suspensions[index] = s;
}

void Car::setWheel(int index, const Wheel& w) {
    if (index >= 0 && index < PARTS_COUNT) wheels[index] = w;
}

void Car::setTire(int index, const Tire& t) {
    if (index >= 0 && index < PARTS_COUNT) tires[index] = t;
}

void Car::setBrake(int index, const Brake& br) {
    if (index >= 0 && index < PARTS_COUNT) brakes[index] = br;
}

string Car::getRegistrationNum() const { return registrationNum; }
int Car::getYear() const { return year; }
string Car::getLicenseNumber() const { return licenseNumber; }
CarModel Car::getModel() const { return model; }
GearBox Car::getGearBox() const { return gearBox; }
Engine Car::getEngine() const { return engine; }
Body Car::getBody() const { return body; }

Suspension Car::getSuspension(int index) const {
    if (index >= 0 && index < PARTS_COUNT) return suspensions[index];
    return Suspension();
}

Wheel Car::getWheel(int index) const {
    if (index >= 0 && index < PARTS_COUNT) return wheels[index];
    return Wheel();
}

Tire Car::getTire(int index) const {
    if (index >= 0 && index < PARTS_COUNT) return tires[index];
    return Tire();
}

Brake Car::getBrake(int index) const {
    if (index >= 0 && index < PARTS_COUNT) return brakes[index];
    return Brake();
}

void Car::moveForward() const { cout << "Автомобиль движется вперед.\n"; }
void Car::moveBackward() const { cout << "Автомобиль движется назад.\n"; }
void Car::stop() const { cout << "Автомобиль остановлен.\n"; }
void Car::turnRight() const { cout << "Автомобиль поворачивает направо.\n"; }
void Car::turnLeft() const { cout << "Автомобиль поворачивает налево.\n"; }

void Car::inputBasic() {
    registrationNum = inputLine("Введите registrationNum: ");
    year = inputInt("Введите year: ");
    licenseNumber = inputLine("Введите licenseNumber: ");
}

void Car::print() const {
    cout << "\n===== CAR =====\n";
    cout << "registrationNum = " << registrationNum << endl;
    cout << "year = " << year << endl;
    cout << "licenseNumber = " << licenseNumber << endl;

    model.print();
    gearBox.print();
    engine.print();
    body.print();

    for (int i = 0; i < PARTS_COUNT; i++) {
        cout << "Подвеска #" << i + 1 << ": ";
        suspensions[i].print();
        cout << "Колесо #" << i + 1 << ": ";
        wheels[i].print();
        cout << "Шина #" << i + 1 << ": ";
        tires[i].print();
        cout << "Тормоз #" << i + 1 << ": ";
        brakes[i].print();
    }
}

void runLab5() {
    cout << "\n===== ЛАБОРАТОРНАЯ РАБОТА 5 =====\n";
    cout << "Тема: Станция технического обслуживания автомобилей\n";

    int modelCount = inputInt("\nВведите количество объектов CarModel: ");
    CarModel* models = new CarModel[modelCount];
    for (int i = 0; i < modelCount; i++) {
        cout << "\nCarModel #" << i << endl;
        models[i].input();
    }

    int gearBoxTypeCount = inputInt("\nВведите количество объектов GearBoxType: ");
    GearBoxType* gearBoxTypes = new GearBoxType[gearBoxTypeCount];
    for (int i = 0; i < gearBoxTypeCount; i++) {
        cout << "\nGearBoxType #" << i << endl;
        gearBoxTypes[i].input();
    }

    int gearBoxCount = inputInt("\nВведите количество объектов GearBox: ");
    GearBox* gearBoxes = new GearBox[gearBoxCount];
    for (int i = 0; i < gearBoxCount; i++) {
        cout << "\nGearBox #" << i << endl;
        int typeIndex = chooseIndex("Выберите индекс GearBoxType: ", gearBoxTypeCount);
        gearBoxes[i].setType(gearBoxTypes[typeIndex]);

        int count = inputInt("Введите количество передач (1-6): ");
        if (count < 1) count = 1;
        if (count > MAX_GEARS) count = MAX_GEARS;

        float ratios[MAX_GEARS];
        for (int j = 0; j < count; j++) {
            ratios[j] = static_cast<float>(inputDouble("Введите передаточное число передачи " + to_string(j + 1) + ": "));
        }
        gearBoxes[i].setRatios(ratios, count);

        int cur = inputInt("Введите текущую передачу: ");
        gearBoxes[i].setCurrentGear(cur);
    }

    int engineCount = inputInt("\nВведите количество объектов Engine: ");
    Engine* engines = new Engine[engineCount];
    for (int i = 0; i < engineCount; i++) {
        cout << "\nEngine #" << i << endl;
        engines[i].input();
    }

    int bodyCount = inputInt("\nВведите количество объектов Body: ");
    Body* bodies = new Body[bodyCount];
    for (int i = 0; i < bodyCount; i++) {
        cout << "\nBody #" << i << endl;
        bodies[i].input();
    }

    int suspensionCount = inputInt("\nВведите количество объектов Suspension: ");
    Suspension* suspensions = new Suspension[suspensionCount];
    for (int i = 0; i < suspensionCount; i++) {
        cout << "\nSuspension #" << i << endl;
        suspensions[i].input();
    }

    int tireCount = inputInt("\nВведите количество объектов Tire: ");
    Tire* tires = new Tire[tireCount];
    for (int i = 0; i < tireCount; i++) {
        cout << "\nTire #" << i << endl;
        tires[i].input();
    }

    int wheelCount = inputInt("\nВведите количество объектов Wheel: ");
    Wheel* wheels = new Wheel[wheelCount];
    for (int i = 0; i < wheelCount; i++) {
        cout << "\nWheel #" << i << endl;
        wheels[i].input();
    }

    int brakeCount = inputInt("\nВведите количество объектов Brake: ");
    Brake* brakes = new Brake[brakeCount];
    for (int i = 0; i < brakeCount; i++) {
        cout << "\nBrake #" << i << endl;
        brakes[i].input();
    }

    int carCount = inputInt("\nВведите количество объектов Car: ");
    Car* cars = new Car[carCount];

    for (int i = 0; i < carCount; i++) {
        cout << "\n===== Создание Car #" << i << " =====\n";
        cars[i].inputBasic();

        int modelIndex = chooseIndex("Выберите индекс CarModel: ", modelCount);
        int gearBoxIndex = chooseIndex("Выберите индекс GearBox: ", gearBoxCount);
        int engineIndex = chooseIndex("Выберите индекс Engine: ", engineCount);
        int bodyIndex = chooseIndex("Выберите индекс Body: ", bodyCount);

        cars[i].setModel(models[modelIndex]);
        cars[i].setGearBox(gearBoxes[gearBoxIndex]);
        cars[i].setEngine(engines[engineIndex]);
        cars[i].setBody(bodies[bodyIndex]);

        for (int j = 0; j < PARTS_COUNT; j++) {
            cout << "\nДля позиции #" << j + 1 << endl;

            int sIndex = chooseIndex("Выберите индекс Suspension: ", suspensionCount);
            int wIndex = chooseIndex("Выберите индекс Wheel: ", wheelCount);
            int tIndex = chooseIndex("Выберите индекс Tire: ", tireCount);
            int bIndex = chooseIndex("Выберите индекс Brake: ", brakeCount);

            cars[i].setSuspension(j, suspensions[sIndex]);
            cars[i].setWheel(j, wheels[wIndex]);
            cars[i].setTire(j, tires[tIndex]);
            cars[i].setBrake(j, brakes[bIndex]);
        }
    }

    cout << "\n\n========== ВЫВОД ВСЕХ МАССИВОВ ==========\n";

    cout << "\n--- CarModel ---\n";
    for (int i = 0; i < modelCount; i++) {
        cout << "[" << i << "] ";
        models[i].print();
    }

    cout << "\n--- GearBoxType ---\n";
    for (int i = 0; i < gearBoxTypeCount; i++) {
        cout << "[" << i << "] ";
        gearBoxTypes[i].print();
    }

    cout << "\n--- GearBox ---\n";
    for (int i = 0; i < gearBoxCount; i++) {
        cout << "[" << i << "] ";
        gearBoxes[i].print();
    }

    cout << "\n--- Engine ---\n";
    for (int i = 0; i < engineCount; i++) {
        cout << "[" << i << "] ";
        engines[i].print();
    }

    cout << "\n--- Body ---\n";
    for (int i = 0; i < bodyCount; i++) {
        cout << "[" << i << "] ";
        bodies[i].print();
    }

    cout << "\n--- Suspension ---\n";
    for (int i = 0; i < suspensionCount; i++) {
        cout << "[" << i << "] ";
        suspensions[i].print();
    }

    cout << "\n--- Tire ---\n";
    for (int i = 0; i < tireCount; i++) {
        cout << "[" << i << "] ";
        tires[i].print();
    }

    cout << "\n--- Wheel ---\n";
    for (int i = 0; i < wheelCount; i++) {
        cout << "[" << i << "] ";
        wheels[i].print();
    }

    cout << "\n--- Brake ---\n";
    for (int i = 0; i < brakeCount; i++) {
        cout << "[" << i << "] ";
        brakes[i].print();
    }

    cout << "\n--- Car ---\n";
    for (int i = 0; i < carCount; i++) {
        cout << "\nCar index = " << i << endl;
        cars[i].print();
    }

    if (carCount > 0) {
        cout << "\n===== Демонстрация методов первого автомобиля =====\n";
        cars[0].moveForward();
        cars[0].moveBackward();
        cars[0].turnRight();
        cars[0].turnLeft();
        cars[0].stop();

        cout << "\nМетоды Engine первого автомобиля:\n";
        cars[0].getEngine().start();
        cars[0].getEngine().accelerate();
        cars[0].getEngine().brake();

        cout << "\nМетод Brake первой тормозной системы:\n";
        cars[0].getBrake(0).apply();
    }

    delete[] models;
    delete[] gearBoxTypes;
    delete[] gearBoxes;
    delete[] engines;
    delete[] bodies;
    delete[] suspensions;
    delete[] tires;
    delete[] wheels;
    delete[] brakes;
    delete[] cars;

    pressEnter();
}