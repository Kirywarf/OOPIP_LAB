#ifndef LAB9_H
#define LAB9_H

#include <string>
#include <exception>

class CatalogException : public std::exception {
private:
    std::string message;

public:
    CatalogException(const std::string& msg);
    const char* what() const noexcept override;
};

class Device {
protected:
    std::string brand;
    std::string model;
    double price;

public:
    Device();
    Device(const std::string& b, const std::string& m, double p);
    Device(const Device& other);
    Device& operator=(const Device& other);
    virtual ~Device();

    void setBrand(const std::string& b);
    void setModel(const std::string& m);
    void setPrice(double p);

    std::string getBrand() const;
    std::string getModel() const;
    double getPrice() const;

    virtual std::string getType() const = 0;
    virtual void printInfo() const = 0;
};

class Smartphone : public Device {
private:
    int memoryGB;
    bool has5G;

public:
    Smartphone();
    Smartphone(const std::string& b, const std::string& m, double p, int mem, bool g5);
    Smartphone(const Smartphone& other);
    Smartphone& operator=(const Smartphone& other);
    ~Smartphone();

    void setMemoryGB(int mem);
    void setHas5G(bool g5);

    int getMemoryGB() const;
    bool getHas5G() const;

    std::string getType() const override;
    void printInfo() const override;
};

class Tablet : public Device {
private:
    double screenSize;
    bool stylusSupport;

public:
    Tablet();
    Tablet(const std::string& b, const std::string& m, double p, double size, bool stylus);
    Tablet(const Tablet& other);
    Tablet& operator=(const Tablet& other);
    ~Tablet();

    void setScreenSize(double size);
    void setStylusSupport(bool stylus);

    double getScreenSize() const;
    bool getStylusSupport() const;

    std::string getType() const override;
    void printInfo() const override;
};

class Customer {
private:
    std::string fullName;
    std::string phone;

public:
    Customer();
    Customer(const std::string& n, const std::string& ph);
    Customer(const Customer& other);
    Customer& operator=(const Customer& other);
    ~Customer();

    void setFullName(const std::string& n);
    void setPhone(const std::string& ph);

    std::string getFullName() const;
    std::string getPhone() const;
};

class OrderItem {
private:
    Device* device;   // агрегация
    int quantity;

public:
    OrderItem();
    OrderItem(Device* d, int q);
    OrderItem(const OrderItem& other);
    OrderItem& operator=(const OrderItem& other);
    ~OrderItem();

    void setDevice(Device* d);
    void setQuantity(int q);

    Device* getDevice() const;
    int getQuantity() const;
    double getCost() const;
};

class Order {
private:
    Customer customer;   // композиция
    OrderItem item;      // композиция
    std::string deliveryType;

public:
    Order();
    Order(const Customer& c, const OrderItem& i, const std::string& delivery);
    Order(const Order& other);
    Order& operator=(const Order& other);
    ~Order();

    void setCustomer(const Customer& c);
    void setItem(const OrderItem& i);
    void setDeliveryType(const std::string& d);

    Customer getCustomer() const;
    OrderItem getItem() const;
    std::string getDeliveryType() const;

    void print() const;
};

void customTerminate();
void runLab9();

#endif