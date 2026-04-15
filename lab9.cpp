#include "Lab9.h"
#include "Utils.h"
#include <iostream>
#include <memory>
#include <new>
#include <exception>
#include <cstdlib>

using namespace std;

// ==================== CatalogException ====================

CatalogException::CatalogException(const string& msg) : message(msg) {}

const char* CatalogException::what() const noexcept {
    return message.c_str();
}

// ==================== Device ====================

Device::Device() : brand(""), model(""), price(0) {
    cout << "Сработал конструктор Device" << endl;
}

Device::Device(const string& b, const string& m, double p)
    : brand(b), model(m), price(p) {
    cout << "Сработал конструктор Device с параметрами" << endl;

    if (b.empty()) throw invalid_argument("Бренд не может быть пустым");
    if (m.empty()) throw invalid_argument("Модель не может быть пустой");
    if (p < 0) throw CatalogException("Цена устройства не может быть отрицательной");
}

Device::Device(const Device& other)
    : brand(other.brand), model(other.model), price(other.price) {
    cout << "Сработал конструктор копирования Device" << endl;
}

Device& Device::operator=(const Device& other) {
    if (this != &other) {
        brand = other.brand;
        model = other.model;
        price = other.price;
    }
    return *this;
}

Device::~Device() {
    cout << "Сработал деструктор Device" << endl;
}

void Device::setBrand(const string& b) {
    if (b.empty()) throw invalid_argument("Бренд не может быть пустым");
    brand = b;
}

void Device::setModel(const string& m) {
    if (m.empty()) throw invalid_argument("Модель не может быть пустой");
    model = m;
}

void Device::setPrice(double p) {
    if (p < 0) throw CatalogException("Цена не может быть отрицательной");
    price = p;
}

string Device::getBrand() const { return brand; }
string Device::getModel() const { return model; }
double Device::getPrice() const { return price; }

// ==================== Smartphone ====================

Smartphone::Smartphone() : Device(), memoryGB(0), has5G(false) {
    cout << "Сработал конструктор Smartphone" << endl;
}

Smartphone::Smartphone(const string& b, const string& m, double p, int mem, bool g5)
    : Device(b, m, p), memoryGB(mem), has5G(g5) {
    cout << "Сработал конструктор Smartphone с параметрами" << endl;

    if (mem <= 0) throw out_of_range("Объем памяти смартфона должен быть больше 0");
}

Smartphone::Smartphone(const Smartphone& other)
    : Device(other), memoryGB(other.memoryGB), has5G(other.has5G) {
    cout << "Сработал конструктор копирования Smartphone" << endl;
}

Smartphone& Smartphone::operator=(const Smartphone& other) {
    if (this != &other) {
        Device::operator=(other);
        memoryGB = other.memoryGB;
        has5G = other.has5G;
    }
    return *this;
}

Smartphone::~Smartphone() {
    cout << "Сработал деструктор Smartphone" << endl;
}

void Smartphone::setMemoryGB(int mem) {
    if (mem <= 0) throw out_of_range("Память смартфона должна быть больше 0");
    memoryGB = mem;
}

void Smartphone::setHas5G(bool g5) {
    has5G = g5;
}

int Smartphone::getMemoryGB() const { return memoryGB; }
bool Smartphone::getHas5G() const { return has5G; }

string Smartphone::getType() const {
    return "Смартфон";
}

void Smartphone::printInfo() const {
    cout << "Тип: " << getType() << endl;
    cout << "Бренд: " << brand << endl;
    cout << "Модель: " << model << endl;
    cout << "Цена: " << price << endl;
    cout << "Память: " << memoryGB << " ГБ" << endl;
    cout << "5G: " << (has5G ? "Да" : "Нет") << endl;
}

// ==================== Tablet ====================

Tablet::Tablet() : Device(), screenSize(0), stylusSupport(false) {
    cout << "Сработал конструктор Tablet" << endl;
}

Tablet::Tablet(const string& b, const string& m, double p, double size, bool stylus)
    : Device(b, m, p), screenSize(size), stylusSupport(stylus) {
    cout << "Сработал конструктор Tablet с параметрами" << endl;

    if (size <= 0) throw range_error("Диагональ экрана планшета должна быть больше 0");
}

Tablet::Tablet(const Tablet& other)
    : Device(other), screenSize(other.screenSize), stylusSupport(other.stylusSupport) {
    cout << "Сработал конструктор копирования Tablet" << endl;
}

Tablet& Tablet::operator=(const Tablet& other) {
    if (this != &other) {
        Device::operator=(other);
        screenSize = other.screenSize;
        stylusSupport = other.stylusSupport;
    }
    return *this;
}

Tablet::~Tablet() {
    cout << "Сработал деструктор Tablet" << endl;
}

void Tablet::setScreenSize(double size) {
    if (size <= 0) throw range_error("Диагональ экрана должна быть больше 0");
    screenSize = size;
}

void Tablet::setStylusSupport(bool stylus) {
    stylusSupport = stylus;
}

double Tablet::getScreenSize() const { return screenSize; }
bool Tablet::getStylusSupport() const { return stylusSupport; }

string Tablet::getType() const {
    return "Планшет";
}

void Tablet::printInfo() const {
    cout << "Тип: " << getType() << endl;
    cout << "Бренд: " << brand << endl;
    cout << "Модель: " << model << endl;
    cout << "Цена: " << price << endl;
    cout << "Диагональ: " << screenSize << endl;
    cout << "Поддержка стилуса: " << (stylusSupport ? "Да" : "Нет") << endl;
}

// ==================== Customer ====================

Customer::Customer() : fullName(""), phone("") {
    cout << "Сработал конструктор Customer" << endl;
}

Customer::Customer(const string& n, const string& ph) : fullName(n), phone(ph) {
    cout << "Сработал конструктор Customer с параметрами" << endl;

    if (n.empty()) throw invalid_argument("ФИО покупателя не может быть пустым");
    if (ph.length() < 5) throw length_error("Телефон слишком короткий");
}

Customer::Customer(const Customer& other)
    : fullName(other.fullName), phone(other.phone) {
    cout << "Сработал конструктор копирования Customer" << endl;
}

Customer& Customer::operator=(const Customer& other) {
    if (this != &other) {
        fullName = other.fullName;
        phone = other.phone;
    }
    return *this;
}

Customer::~Customer() {
    cout << "Сработал деструктор Customer" << endl;
}

void Customer::setFullName(const string& n) {
    if (n.empty()) throw invalid_argument("ФИО не может быть пустым");
    fullName = n;
}

void Customer::setPhone(const string& ph) {
    if (ph.length() < 5) throw length_error("Телефон слишком короткий");
    phone = ph;
}

string Customer::getFullName() const { return fullName; }
string Customer::getPhone() const { return phone; }

// ==================== OrderItem ====================

OrderItem::OrderItem() : device(nullptr), quantity(0) {
    cout << "Сработал конструктор OrderItem" << endl;
}

OrderItem::OrderItem(Device* d, int q) : device(d), quantity(q) {
    cout << "Сработал конструктор OrderItem с параметрами" << endl;

    if (d == nullptr) throw CatalogException("Устройство для заказа не выбрано");
    if (q <= 0) throw overflow_error("Количество должно быть больше 0");
}

OrderItem::OrderItem(const OrderItem& other)
    : device(other.device), quantity(other.quantity) {
    cout << "Сработал конструктор копирования OrderItem" << endl;
}

OrderItem& OrderItem::operator=(const OrderItem& other) {
    if (this != &other) {
        device = other.device;
        quantity = other.quantity;
    }
    return *this;
}

OrderItem::~OrderItem() {
    cout << "Сработал деструктор OrderItem" << endl;
}

void OrderItem::setDevice(Device* d) {
    if (d == nullptr) throw CatalogException("Нулевой указатель на устройство");
    device = d;
}

void OrderItem::setQuantity(int q) {
    if (q <= 0) throw overflow_error("Количество должно быть больше 0");
    quantity = q;
}

Device* OrderItem::getDevice() const { return device; }
int OrderItem::getQuantity() const { return quantity; }

double OrderItem::getCost() const {
    if (device == nullptr) throw CatalogException("Невозможно вычислить стоимость: устройство отсутствует");
    return device->getPrice() * quantity;
}

// ==================== Order ====================

Order::Order() : customer(), item(), deliveryType("") {
    cout << "Сработал конструктор Order" << endl;
}

Order::Order(const Customer& c, const OrderItem& i, const string& delivery)
    : customer(c), item(i), deliveryType(delivery) {
    cout << "Сработал конструктор Order с параметрами" << endl;

    if (delivery.empty()) throw CatalogException("Способ доставки не указан");
    if (delivery != "Самовывоз" && delivery != "Курьер" && delivery != "Почта")
        throw range_error("Недопустимый способ доставки");
}

Order::Order(const Order& other)
    : customer(other.customer), item(other.item), deliveryType(other.deliveryType) {
    cout << "Сработал конструктор копирования Order" << endl;
}

Order& Order::operator=(const Order& other) {
    if (this != &other) {
        customer = other.customer;
        item = other.item;
        deliveryType = other.deliveryType;
    }
    return *this;
}

Order::~Order() {
    cout << "Сработал деструктор Order" << endl;
}

void Order::setCustomer(const Customer& c) { customer = c; }
void Order::setItem(const OrderItem& i) { item = i; }

void Order::setDeliveryType(const string& d) {
    if (d.empty()) throw CatalogException("Способ доставки пустой");
    if (d != "Самовывоз" && d != "Курьер" && d != "Почта")
        throw range_error("Недопустимый способ доставки");
    deliveryType = d;
}

Customer Order::getCustomer() const { return customer; }
OrderItem Order::getItem() const { return item; }
string Order::getDeliveryType() const { return deliveryType; }

void Order::print() const {
    if (item.getDevice() == nullptr) throw CatalogException("В заказе отсутствует устройство");

    cout << "\n===== ДАННЫЕ ЗАКАЗА =====\n";
    cout << "Покупатель: " << customer.getFullName() << endl;
    cout << "Телефон: " << customer.getPhone() << endl;
    cout << "Способ доставки: " << deliveryType << endl;
    cout << "Количество: " << item.getQuantity() << endl;
    cout << "Стоимость: " << item.getCost() << endl;
    cout << "\nУстройство:\n";
    item.getDevice()->printInfo();
}

// ==================== terminate ====================

void customTerminate() {
    cerr << "\nСработала пользовательская функция завершения customTerminate().\n";
    exit(-1);
}

// ==================== Вспомогательные функции ====================

static unique_ptr<Device> createDeviceWithRethrow() {
    try {
        int type = inputInt("1 - Смартфон, 2 - Планшет: ");

        if (type == 1) {
            string brand = inputLine("Бренд: ");
            string model = inputLine("Модель: ");
            double price = inputDouble("Цена: ");
            int memory = inputInt("Память (ГБ): ");
            bool has5G = inputInt("Поддержка 5G? (1-да, 0-нет): ") == 1;

            return unique_ptr<Device>(new Smartphone(brand, model, price, memory, has5G));
        }
        else if (type == 2) {
            string brand = inputLine("Бренд: ");
            string model = inputLine("Модель: ");
            double price = inputDouble("Цена: ");
            double screen = inputDouble("Диагональ экрана: ");
            bool stylus = inputInt("Поддержка стилуса? (1-да, 0-нет): ") == 1;

            return unique_ptr<Device>(new Tablet(brand, model, price, screen, stylus));
        }
        else {
            throw invalid_argument("Выбран неверный тип устройства");
        }
    }
    catch (const exception& e) {
        cout << "Локальная обработка в createDeviceWithRethrow(): " << e.what() << endl;
        throw;
    }
}

static void demoConstructorException() {
    cout << "\n===== ДЕМОНСТРАЦИЯ ИСКЛЮЧЕНИЯ В КОНСТРУКТОРЕ =====\n";
    try {
        Smartphone badPhone("Samsung", "BrokenPhone", 1200, 0, true);
        badPhone.printInfo();
    }
    catch (const exception& e) {
        cout << "Поймано исключение: " << e.what() << endl;
    }
}

static void demoBadAlloc() {
    cout << "\n===== ДЕМОНСТРАЦИЯ ИСКЛЮЧЕНИЯ bad_alloc =====\n";
    try {
        size_t huge = static_cast<size_t>(-1) / sizeof(double);
        double* p = new double[huge];
        delete[] p;
    }
    catch (const bad_alloc& e) {
        cout << "Поймано исключение bad_alloc: " << e.what() << endl;
    }
}

static void demoTerminate() {
    cout << "\n===== ДЕМОНСТРАЦИЯ customTerminate =====\n";
    cout << "Сейчас будет сгенерировано необработанное исключение.\n";
    throw 3.14159;
}

// ==================== runLab9 ====================

void runLab9() {
    set_terminate(customTerminate);

    int choice;
    do {
        cout << "\n===== ЛАБОРАТОРНАЯ РАБОТА 9 =====\n";
        cout << "1. Оформить заказ\n";
        cout << "2. Показать исключение в конструкторе\n";
        cout << "3. Показать исключение bad_alloc\n";
        cout << "4. Показать customTerminate (программа завершится)\n";
        cout << "0. Выход из лабораторной\n";

        choice = inputInt("Ваш выбор: ");

        if (choice == 1) {
            try {
                unique_ptr<Device> device = createDeviceWithRethrow();

                Customer customer(
                    inputLine("ФИО покупателя: "),
                    inputLine("Телефон: ")
                );

                OrderItem item(device.get(), inputInt("Количество: "));
                Order order(customer, item, inputLine("Способ доставки (Самовывоз/Курьер/Почта): "));
                order.print();
            }
            catch (const CatalogException& e) {
                cout << "CatalogException: " << e.what() << endl;
            }
            catch (const invalid_argument& e) {
                cout << "invalid_argument: " << e.what() << endl;
            }
            catch (const out_of_range& e) {
                cout << "out_of_range: " << e.what() << endl;
            }
            catch (const range_error& e) {
                cout << "range_error: " << e.what() << endl;
            }
            catch (const overflow_error& e) {
                cout << "overflow_error: " << e.what() << endl;
            }
            catch (const length_error& e) {
                cout << "length_error: " << e.what() << endl;
            }
            catch (const exception& e) {
                cout << "std::exception: " << e.what() << endl;
            }
            catch (...) {
                cout << "Сработал абсолютный обработчик catch(...)" << endl;
            }
        }
        else if (choice == 2) {
            demoConstructorException();
        }
        else if (choice == 3) {
            demoBadAlloc();
        }
        else if (choice == 4) {
            demoTerminate();
        }
        else if (choice == 0) {
            cout << "Выход из ЛР9.\n";
        }
        else {
            cout << "Неверный пункт меню.\n";
        }

    } while (choice != 0);

    pressEnter();
}