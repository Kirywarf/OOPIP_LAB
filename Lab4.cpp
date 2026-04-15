#ifndef LAB4_H
#define LAB4_H

#include "Lab4.h"
#include <string>
#include <fstream>

class MobileApp {
protected:
    std::string appName;
    std::string version;
    std::string creationDate;
    std::string operatingSystem;
    double sizeMB;
    std::string developer;

public:
    MobileApp();
    MobileApp(const std::string& name, const std::string& ver, const std::string& date,
        const std::string& os, double size, const std::string& dev);
    MobileApp(const MobileApp& other);
    MobileApp& operator=(const MobileApp& other);
    virtual ~MobileApp();

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

    virtual void input();
    virtual void print() const;
    virtual void saveToFile(std::ofstream& fout) const;
    virtual std::string getType() const;

    bool matchesOS(const std::string& os) const;
    bool matchesYear(int year) const;
    int extractYear() const;
};

class GameApp : public MobileApp {
private:
    std::string genre;
    int ageLimit;

public:
    GameApp();
    GameApp(const std::string& name, const std::string& ver, const std::string& date,
        const std::string& os, double size, const std::string& dev,
        const std::string& g, int age);
    GameApp(const GameApp& other);
    GameApp& operator=(const GameApp& other);
    virtual ~GameApp();

    void setGenre(const std::string& g);
    void setAgeLimit(int age);
    std::string getGenre() const;
    int getAgeLimit() const;

    virtual void input();
    virtual void print() const;
    virtual void saveToFile(std::ofstream& fout) const;
    virtual std::string getType() const;
};

class BusinessApp : public MobileApp {
private:
    std::string category;
    bool cloudSync;

public:
    BusinessApp();
    BusinessApp(const std::string& name, const std::string& ver, const std::string& date,
        const std::string& os, double size, const std::string& dev,
        const std::string& cat, bool sync);
    BusinessApp(const BusinessApp& other);
    BusinessApp& operator=(const BusinessApp& other);
    virtual ~BusinessApp();

    void setCategory(const std::string& cat);
    void setCloudSync(bool sync);
    std::string getCategory() const;
    bool getCloudSync() const;

    virtual void input();
    virtual void print() const;
    virtual void saveToFile(std::ofstream& fout) const;
    virtual std::string getType() const;
};

void runLab4();

#endif