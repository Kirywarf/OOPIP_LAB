#ifndef LAB6_H
#define LAB6_H

#include <string>

class AppRecord {
private:
    std::string appName;
    std::string version;
    std::string creationDate;
    std::string operatingSystem;
    double sizeMB;
    std::string developer;

public:
    AppRecord();
    AppRecord(const std::string& name, const std::string& ver,
        const std::string& date, const std::string& os,
        double size, const std::string& dev);
    AppRecord(const AppRecord& other);
    AppRecord& operator=(const AppRecord& other);
    ~AppRecord();

    void setAppName(const std::string& name);
    void setVersion(const std::string& ver);
    void setCreationDate(const std::string& date);
    void setOperatingSystem(const std::string& os);
    void setSizeMB(double size);
    void setDeveloper(const std::string& dev);

    std::string getAppName() const;
    std::string getVersion() const;
    std::string getCreationDate() const;
    std::string getOperatingSystem() const;
    double getSizeMB() const;
    std::string getDeveloper() const;

    void input();
    void print() const;
    void saveToFile(const std::string& filename) const;

    int getYear() const;
    bool matchesOS(const std::string& os) const;
    bool matchesYear(int year) const;
};

void runLab6();

#endif