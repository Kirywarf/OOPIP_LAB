#ifndef LAB1_H
#define LAB1_H

#include <string>

class MyString {
private:
    std::string data;
    int id;
    static int counter;

public:
    MyString();
    MyString(const std::string& s);
    MyString(const MyString& other);
    MyString& operator=(const MyString& other);
    ~MyString();

    void setData(const std::string& s);
    std::string getData() const;
    int getId() const;
    static int getCounter();

    int length() const;
    bool isEmpty() const;
    void ltrim();
    void rtrim();
    void trim();

    MyString concat(const MyString& other) const;
    MyString concat_ws(const std::string& sep, const MyString& other) const;

    void print() const;
    void saveToFile(const std::string& filename) const;
};

void runLab1();

#endif