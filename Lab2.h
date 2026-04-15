#ifndef LAB2_H
#define LAB2_H

#include <string>
#include <iostream>

class Pair {
private:
    std::string key;
    std::string value;

public:
    Pair();
    Pair(const std::string& k, const std::string& v);
    Pair(const Pair& other);
    Pair& operator=(const Pair& other);
    ~Pair();

    void setKey(const std::string& k);
    void setValue(const std::string& v);

    std::string getKey() const;
    std::string getValue() const;

    bool operator<(const Pair& other) const;
    bool operator>(const Pair& other) const;
    bool operator==(const Pair& other) const;
    bool operator!=(const Pair& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Pair& p);
    friend std::istream& operator>>(std::istream& in, Pair& p);
};

void runLab2();

#endif