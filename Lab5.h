#ifndef LAB5_H
#define LAB5_H

#include <string>

const int MAX_GEARS = 6;
const int PARTS_COUNT = 4;

class CarModel {
private:
    std::string title;

public:
    CarModel();
    CarModel(const std::string& t);
    CarModel(const CarModel& other);
    ~CarModel();

    void setTitle(const std::string& t);
    std::string getTitle() const;

    void input();
    void print() const;
};

class GearBoxType {
private:
    std::string name;
    std::string remarks;

public:
    GearBoxType();
    GearBoxType(const std::string& n, const std::string& r);
    GearBoxType(const GearBoxType& other);
    ~GearBoxType();

    void setName(const std::string& n);
    void setRemarks(const std::string& r);

    std::string getName() const;
    std::string getRemarks() const;

    void input();
    void print() const;
};

class GearBox {
private:
    GearBoxType type;
    float gearRatio[MAX_GEARS];
    int gearCount;
    int currentGear;

public:
    GearBox();
    GearBox(const GearBoxType& t, const float ratios[], int count, int current);
    GearBox(const GearBox& other);
    ~GearBox();

    void setType(const GearBoxType& t);
    void setRatios(const float ratios[], int count);
    void setCurrentGear(int gear);

    GearBoxType getType() const;
    int getGearCount() const;
    int getCurrentGear() const;
    float getGearRatio(int index) const;

    void shiftUp();
    void shiftDown();

    void input();
    void print() const;
};

class Engine {
private:
    float capacity;
    int numberOfCylinders;

public:
    Engine();
    Engine(float c, int n);
    Engine(const Engine& other);
    ~Engine();

    void setCapacity(float c);
    void setNumberOfCylinders(int n);

    float getCapacity() const;
    int getNumberOfCylinders() const;

    void start() const;
    void brake() const;
    void accelerate() const;

    void input();
    void print() const;
};

class Body {
private:
    int numberOfDoors;

public:
    Body();
    Body(int d);
    Body(const Body& other);
    ~Body();

    void setNumberOfDoors(int d);
    int getNumberOfDoors() const;

    void input();
    void print() const;
};

class Suspension {
private:
    float springRate;

public:
    Suspension();
    Suspension(float s);
    Suspension(const Suspension& other);
    ~Suspension();

    void setSpringRate(float s);
    float getSpringRate() const;

    void input();
    void print() const;
};

class Tire {
private:
    float width;
    float airPressure;

public:
    Tire();
    Tire(float w, float a);
    Tire(const Tire& other);
    ~Tire();

    void setWidth(float w);
    void setAirPressure(float a);

    float getWidth() const;
    float getAirPressure() const;

    void input();
    void print() const;
};

class Wheel {
private:
    float diameter;

public:
    Wheel();
    Wheel(float d);
    Wheel(const Wheel& other);
    ~Wheel();

    void setDiameter(float d);
    float getDiameter() const;

    void input();
    void print() const;
};

class Brake {
private:
    std::string type;

public:
    Brake();
    Brake(const std::string& t);
    Brake(const Brake& other);
    ~Brake();

    void setType(const std::string& t);
    std::string getType() const;

    void apply() const;

    void input();
    void print() const;
};

class Car {
private:
    std::string registrationNum;
    int year;
    std::string licenseNumber;

    CarModel model;
    GearBox gearBox;
    Engine engine;
    Body body;

    Suspension suspensions[PARTS_COUNT];
    Wheel wheels[PARTS_COUNT];
    Tire tires[PARTS_COUNT];
    Brake brakes[PARTS_COUNT];

public:
    Car();
    Car(const std::string& reg, int y, const std::string& lic,
        const CarModel& m, const GearBox& g, const Engine& e, const Body& b,
        const Suspension s[], const Wheel w[], const Tire t[], const Brake br[]);
    Car(const Car& other);
    ~Car();

    void setRegistrationNum(const std::string& reg);
    void setYear(int y);
    void setLicenseNumber(const std::string& lic);
    void setModel(const CarModel& m);
    void setGearBox(const GearBox& g);
    void setEngine(const Engine& e);
    void setBody(const Body& b);
    void setSuspension(int index, const Suspension& s);
    void setWheel(int index, const Wheel& w);
    void setTire(int index, const Tire& t);
    void setBrake(int index, const Brake& br);

    std::string getRegistrationNum() const;
    int getYear() const;
    std::string getLicenseNumber() const;
    CarModel getModel() const;
    GearBox getGearBox() const;
    Engine getEngine() const;
    Body getBody() const;
    Suspension getSuspension(int index) const;
    Wheel getWheel(int index) const;
    Tire getTire(int index) const;
    Brake getBrake(int index) const;

    void moveForward() const;
    void moveBackward() const;
    void stop() const;
    void turnRight() const;
    void turnLeft() const;

    void inputBasic();
    void print() const;
};

void runLab5();

#endif