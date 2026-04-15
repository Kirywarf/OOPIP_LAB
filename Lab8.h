#ifndef LAB8_H
#define LAB8_H

#include <string>
#include <memory>
#include <fstream>

class GEngine {
private:
    std::string name;

public:
    GEngine();
    GEngine(const std::string& n);
    GEngine(const GEngine& other);
    GEngine& operator=(const GEngine& other);
    ~GEngine();

    void setName(const std::string& n);
    std::string getName() const;
};

class GMusic {
private:
    std::string composer;

public:
    GMusic();
    GMusic(const std::string& c);
    GMusic(const GMusic& other);
    GMusic& operator=(const GMusic& other);
    ~GMusic();

    void setComposer(const std::string& c);
    std::string getComposer() const;
};

class GSetting {
private:
    std::string world;

public:
    GSetting();
    GSetting(const std::string& w);
    GSetting(const GSetting& other);
    GSetting& operator=(const GSetting& other);
    ~GSetting();

    void setWorld(const std::string& w);
    std::string getWorld() const;
};

class GCharacter {
private:
    std::string hero;

public:
    GCharacter();
    GCharacter(const std::string& h);
    GCharacter(const GCharacter& other);
    GCharacter& operator=(const GCharacter& other);
    ~GCharacter();

    void setHero(const std::string& h);
    std::string getHero() const;
};

class GGame {
private:
    std::string title;
    std::string genre;
    int year;
    GEngine engine;
    GMusic music;
    GSetting setting;
    GCharacter character;

public:
    GGame();
    GGame(const std::string& t, const std::string& g, int y,
        const GEngine& e, const GMusic& m, const GSetting& s, const GCharacter& c);
    GGame(const GGame& other);
    GGame& operator=(const GGame& other);
    ~GGame();

    void setTitle(const std::string& t);
    void setGenre(const std::string& g);
    void setYear(int y);
    void setEngine(const GEngine& e);
    void setMusic(const GMusic& m);
    void setSetting(const GSetting& s);
    void setCharacter(const GCharacter& c);

    std::string getTitle() const;
    std::string getGenre() const;
    int getYear() const;
    GEngine getEngine() const;
    GMusic getMusic() const;
    GSetting getSetting() const;
    GCharacter getCharacter() const;

    void printRow() const;
    void saveRow(std::ofstream& fout) const;
};

template <class T>
class SmartBox {
private:
    std::shared_ptr<T> ptr;

public:
    SmartBox() : ptr(nullptr) {}
    SmartBox(std::shared_ptr<T> p) : ptr(p) {}
    SmartBox(const SmartBox<T>& other) : ptr(other.ptr) {}
    SmartBox<T>& operator=(const SmartBox<T>& other) {
        if (this != &other) ptr = other.ptr;
        return *this;
    }
    ~SmartBox() {}

    void set(std::shared_ptr<T> p) { ptr = p; }
    std::shared_ptr<T> get() const { return ptr; }
};

class GameTransaction {
private:
    GGame oldValue;
    std::shared_ptr<GGame> target;
    bool committed;

public:
    GameTransaction(std::shared_ptr<GGame> t);
    ~GameTransaction();

    void apply(const GGame& newValue);
    void commit();
    void rollback();
};

bool validateSetting(const std::string& value);
bool validateMusic(const std::string& value);

void runLab8();

#endif