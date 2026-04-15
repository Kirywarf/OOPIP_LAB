#ifndef LAB7_H
#define LAB7_H

#include <string>
#include <fstream>

namespace lab7 {

    class Engine {
    private:
        std::string name;
        std::string version;

    public:
        Engine();
        Engine(const std::string& n, const std::string& v);
        Engine(const Engine& other);
        Engine& operator=(const Engine& other);
        ~Engine();

        void setName(const std::string& n);
        void setVersion(const std::string& v);
        std::string getName() const;
        std::string getVersion() const;
    };

    class Music {
    private:
        std::string composer;
        std::string style;

    public:
        Music();
        Music(const std::string& c, const std::string& s);
        Music(const Music& other);
        Music& operator=(const Music& other);
        ~Music();

        void setComposer(const std::string& c);
        void setStyle(const std::string& s);
        std::string getComposer() const;
        std::string getStyle() const;
    };

    class Setting {
    private:
        std::string worldName;
        std::string era;

    public:
        Setting();
        Setting(const std::string& w, const std::string& e);
        Setting(const Setting& other);
        Setting& operator=(const Setting& other);
        ~Setting();

        void setWorldName(const std::string& w);
        void setEra(const std::string& e);
        std::string getWorldName() const;
        std::string getEra() const;
    };

    class Character {
    private:
        std::string name;
        std::string role;

    public:
        Character();
        Character(const std::string& n, const std::string& r);
        Character(const Character& other);
        Character& operator=(const Character& other);
        ~Character();

        void setName(const std::string& n);
        void setRole(const std::string& r);
        std::string getName() const;
        std::string getRole() const;
    };

    class Game {
    private:
        std::string title;
        std::string genre;
        int releaseYear;
        Engine engine;
        Music music;
        Setting setting;
        Character mainCharacter;

    public:
        Game();
        Game(const std::string& t, const std::string& g, int y,
            const Engine& e, const Music& m, const Setting& s, const Character& c);
        Game(const Game& other);
        Game& operator=(const Game& other);
        ~Game();

        void setTitle(const std::string& t);
        void setGenre(const std::string& g);
        void setReleaseYear(int y);
        void setEngine(const Engine& e);
        void setMusic(const Music& m);
        void setSetting(const Setting& s);
        void setMainCharacter(const Character& c);

        std::string getTitle() const;
        std::string getGenre() const;
        int getReleaseYear() const;
        Engine getEngine() const;
        Music getMusic() const;
        Setting getSetting() const;
        Character getMainCharacter() const;

        void input();
        void printRow() const;
        void saveRow(std::ofstream& fout) const;
    };

    template <class T>
    class Box {
    private:
        T value;

    public:
        Box() : value() {}
        Box(const T& v) : value(v) {}
        Box(const Box<T>& other) : value(other.value) {}
        Box<T>& operator=(const Box<T>& other) {
            if (this != &other) value = other.value;
            return *this;
        }
        ~Box() {}

        void setValue(const T& v) { value = v; }
        T getValue() const { return value; }
    };

} // namespace lab7

void runLab7();

#endif