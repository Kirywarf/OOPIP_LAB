#include "Lab7.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>

using namespace std;
using namespace lab7;

// Engine
Engine::Engine() : name(""), version("") {}
Engine::Engine(const string& n, const string& v) : name(n), version(v) {}
Engine::Engine(const Engine& other) : name(other.name), version(other.version) {}

Engine& Engine::operator=(const Engine& other) {
    if (this != &other) {
        name = other.name;
        version = other.version;
    }
    return *this;
}

Engine::~Engine() {}
void Engine::setName(const string& n) { name = n; }
void Engine::setVersion(const string& v) { version = v; }
string Engine::getName() const { return name; }
string Engine::getVersion() const { return version; }

// Music
Music::Music() : composer(""), style("") {}
Music::Music(const string& c, const string& s) : composer(c), style(s) {}
Music::Music(const Music& other) : composer(other.composer), style(other.style) {}

Music& Music::operator=(const Music& other) {
    if (this != &other) {
        composer = other.composer;
        style = other.style;
    }
    return *this;
}

Music::~Music() {}
void Music::setComposer(const string& c) { composer = c; }
void Music::setStyle(const string& s) { style = s; }
string Music::getComposer() const { return composer; }
string Music::getStyle() const { return style; }

// Setting
Setting::Setting() : worldName(""), era("") {}
Setting::Setting(const string& w, const string& e) : worldName(w), era(e) {}
Setting::Setting(const Setting& other) : worldName(other.worldName), era(other.era) {}

Setting& Setting::operator=(const Setting& other) {
    if (this != &other) {
        worldName = other.worldName;
        era = other.era;
    }
    return *this;
}

Setting::~Setting() {}
void Setting::setWorldName(const string& w) { worldName = w; }
void Setting::setEra(const string& e) { era = e; }
string Setting::getWorldName() const { return worldName; }
string Setting::getEra() const { return era; }

// Character
Character::Character() : name(""), role("") {}
Character::Character(const string& n, const string& r) : name(n), role(r) {}
Character::Character(const Character& other) : name(other.name), role(other.role) {}

Character& Character::operator=(const Character& other) {
    if (this != &other) {
        name = other.name;
        role = other.role;
    }
    return *this;
}

Character::~Character() {}
void Character::setName(const string& n) { name = n; }
void Character::setRole(const string& r) { role = r; }
string Character::getName() const { return name; }
string Character::getRole() const { return role; }

// Game
Game::Game() : title(""), genre(""), releaseYear(0), engine(), music(), setting(), mainCharacter() {}

Game::Game(const string& t, const string& g, int y,
    const Engine& e, const Music& m, const Setting& s, const Character& c)
    : title(t), genre(g), releaseYear(y), engine(e), music(m), setting(s), mainCharacter(c) {
}

Game::Game(const Game& other)
    : title(other.title), genre(other.genre), releaseYear(other.releaseYear),
    engine(other.engine), music(other.music), setting(other.setting), mainCharacter(other.mainCharacter) {
}

Game& Game::operator=(const Game& other) {
    if (this != &other) {
        title = other.title;
        genre = other.genre;
        releaseYear = other.releaseYear;
        engine = other.engine;
        music = other.music;
        setting = other.setting;
        mainCharacter = other.mainCharacter;
    }
    return *this;
}

Game::~Game() {}

void Game::setTitle(const string& t) { title = t; }
void Game::setGenre(const string& g) { genre = g; }
void Game::setReleaseYear(int y) { releaseYear = y; }
void Game::setEngine(const Engine& e) { engine = e; }
void Game::setMusic(const Music& m) { music = m; }
void Game::setSetting(const Setting& s) { setting = s; }
void Game::setMainCharacter(const Character& c) { mainCharacter = c; }

string Game::getTitle() const { return title; }
string Game::getGenre() const { return genre; }
int Game::getReleaseYear() const { return releaseYear; }
Engine Game::getEngine() const { return engine; }
Music Game::getMusic() const { return music; }
Setting Game::getSetting() const { return setting; }
Character Game::getMainCharacter() const { return mainCharacter; }

void Game::input() {
    title = inputLine("Название игры: ");
    genre = inputLine("Жанр: ");
    releaseYear = inputInt("Год выпуска: ");

    engine.setName(inputLine("Движок: "));
    engine.setVersion(inputLine("Версия движка: "));

    music.setComposer(inputLine("Композитор: "));
    music.setStyle(inputLine("Стиль музыки: "));

    setting.setWorldName(inputLine("Мир / сеттинг: "));
    setting.setEra(inputLine("Эпоха: "));

    mainCharacter.setName(inputLine("Главный персонаж: "));
    mainCharacter.setRole(inputLine("Роль персонажа: "));
}

void Game::printRow() const {
    cout << left
        << setw(15) << title
        << setw(12) << genre
        << setw(8) << releaseYear
        << setw(15) << engine.getName()
        << setw(15) << setting.getWorldName()
        << setw(15) << music.getComposer()
        << setw(15) << mainCharacter.getName()
        << endl;
}

void Game::saveRow(ofstream& fout) const {
    fout << left
        << setw(15) << title
        << setw(12) << genre
        << setw(8) << releaseYear
        << setw(15) << engine.getName()
        << setw(15) << setting.getWorldName()
        << setw(15) << music.getComposer()
        << setw(15) << mainCharacter.getName()
        << endl;
}

void runLab7() {
    cout << "\n===== ЛАБОРАТОРНАЯ РАБОТА 7 =====\n";

    int n = inputInt("Введите количество игр: ");
    if (n <= 0) return;

    Game* arr = new Game[n];

    for (int i = 0; i < n; i++) {
        cout << "\nИгра #" << i + 1 << endl;
        arr[i].input();
    }

    cout << "\n===== Таблица игр =====\n";
    cout << left
        << setw(15) << "Название"
        << setw(12) << "Жанр"
        << setw(8) << "Год"
        << setw(15) << "Движок"
        << setw(15) << "Сеттинг"
        << setw(15) << "Музыка"
        << setw(15) << "Персонаж"
        << endl;

    for (int i = 0; i < n; i++) arr[i].printRow();

    ofstream fout("lab7_games.txt");
    fout << left
        << setw(15) << "Название"
        << setw(12) << "Жанр"
        << setw(8) << "Год"
        << setw(15) << "Движок"
        << setw(15) << "Сеттинг"
        << setw(15) << "Музыка"
        << setw(15) << "Персонаж"
        << endl;
    for (int i = 0; i < n; i++) arr[i].saveRow(fout);
    fout.close();

    Box<string> tag("GameDevCatalog");
    cout << "\nШаблонный класс Box хранит метку: " << tag.getValue() << endl;

    delete[] arr;
    pressEnter();
}