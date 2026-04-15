#include "Lab8.h"
#include "Utils.h"
#include <iostream>
#include <iomanip>

using namespace std;

// GEngine
GEngine::GEngine() : name("") {}
GEngine::GEngine(const string& n) : name(n) {}
GEngine::GEngine(const GEngine& other) : name(other.name) {}

GEngine& GEngine::operator=(const GEngine& other) {
    if (this != &other) name = other.name;
    return *this;
}

GEngine::~GEngine() {}
void GEngine::setName(const string& n) { name = n; }
string GEngine::getName() const { return name; }

// GMusic
GMusic::GMusic() : composer("") {}
GMusic::GMusic(const string& c) : composer(c) {}
GMusic::GMusic(const GMusic& other) : composer(other.composer) {}

GMusic& GMusic::operator=(const GMusic& other) {
    if (this != &other) composer = other.composer;
    return *this;
}

GMusic::~GMusic() {}
void GMusic::setComposer(const string& c) { composer = c; }
string GMusic::getComposer() const { return composer; }

// GSetting
GSetting::GSetting() : world("") {}
GSetting::GSetting(const string& w) : world(w) {}
GSetting::GSetting(const GSetting& other) : world(other.world) {}

GSetting& GSetting::operator=(const GSetting& other) {
    if (this != &other) world = other.world;
    return *this;
}

GSetting::~GSetting() {}
void GSetting::setWorld(const string& w) { world = w; }
string GSetting::getWorld() const { return world; }

// GCharacter
GCharacter::GCharacter() : hero("") {}
GCharacter::GCharacter(const string& h) : hero(h) {}
GCharacter::GCharacter(const GCharacter& other) : hero(other.hero) {}

GCharacter& GCharacter::operator=(const GCharacter& other) {
    if (this != &other) hero = other.hero;
    return *this;
}

GCharacter::~GCharacter() {}
void GCharacter::setHero(const string& h) { hero = h; }
string GCharacter::getHero() const { return hero; }

// GGame
GGame::GGame() : title(""), genre(""), year(0), engine(), music(), setting(), character() {}

GGame::GGame(const string& t, const string& g, int y,
    const GEngine& e, const GMusic& m, const GSetting& s, const GCharacter& c)
    : title(t), genre(g), year(y), engine(e), music(m), setting(s), character(c) {
}

GGame::GGame(const GGame& other)
    : title(other.title), genre(other.genre), year(other.year),
    engine(other.engine), music(other.music), setting(other.setting), character(other.character) {
}

GGame& GGame::operator=(const GGame& other) {
    if (this != &other) {
        title = other.title;
        genre = other.genre;
        year = other.year;
        engine = other.engine;
        music = other.music;
        setting = other.setting;
        character = other.character;
    }
    return *this;
}

GGame::~GGame() {}

void GGame::setTitle(const string& t) { title = t; }
void GGame::setGenre(const string& g) { genre = g; }
void GGame::setYear(int y) { year = y; }
void GGame::setEngine(const GEngine& e) { engine = e; }
void GGame::setMusic(const GMusic& m) { music = m; }
void GGame::setSetting(const GSetting& s) { setting = s; }
void GGame::setCharacter(const GCharacter& c) { character = c; }

string GGame::getTitle() const { return title; }
string GGame::getGenre() const { return genre; }
int GGame::getYear() const { return year; }
GEngine GGame::getEngine() const { return engine; }
GMusic GGame::getMusic() const { return music; }
GSetting GGame::getSetting() const { return setting; }
GCharacter GGame::getCharacter() const { return character; }

void GGame::printRow() const {
    cout << left
        << setw(15) << title
        << setw(12) << genre
        << setw(8) << year
        << setw(15) << engine.getName()
        << setw(15) << setting.getWorld()
        << setw(15) << music.getComposer()
        << setw(15) << character.getHero()
        << endl;
}

void GGame::saveRow(ofstream& fout) const {
    fout << left
        << setw(15) << title
        << setw(12) << genre
        << setw(8) << year
        << setw(15) << engine.getName()
        << setw(15) << setting.getWorld()
        << setw(15) << music.getComposer()
        << setw(15) << character.getHero()
        << endl;
}

// Transaction
GameTransaction::GameTransaction(shared_ptr<GGame> t)
    : oldValue(*t), target(t), committed(false) {
}

GameTransaction::~GameTransaction() {
    if (!committed) rollback();
}

void GameTransaction::apply(const GGame& newValue) {
    *target = newValue;
}

void GameTransaction::commit() {
    committed = true;
}

void GameTransaction::rollback() {
    *target = oldValue;
}

bool validateSetting(const string& value) {
    return value == "Fantasy" ||
        value == "SciFi" ||
        value == "PostApocalypse" ||
        value == "Modern";
}

bool validateMusic(const string& value) {
    return value == "Orchestral" ||
        value == "Electronic" ||
        value == "Rock" ||
        value == "Ambient";
}

void runLab8() {
    cout << "\n===== ЛАБОРАТОРНАЯ РАБОТА 8 =====\n";

    int n = inputInt("Введите количество игр: ");
    if (n <= 0) return;

    shared_ptr<GGame>* arr = new shared_ptr<GGame>[n];

    for (int i = 0; i < n; i++) {
        arr[i] = make_shared<GGame>();

        while (true) {
            cout << "\nИгра #" << i + 1 << endl;

            string title = inputLine("Название: ");
            string genre = inputLine("Жанр: ");
            int year = inputInt("Год: ");
            string engine = inputLine("Движок: ");
            string setting = inputLine("Сеттинг (Fantasy/SciFi/PostApocalypse/Modern): ");
            string music = inputLine("Музыка (Orchestral/Electronic/Rock/Ambient): ");
            string hero = inputLine("Персонаж: ");

            GGame candidate(
                title, genre, year,
                GEngine(engine),
                GMusic(music),
                GSetting(setting),
                GCharacter(hero)
            );

            GameTransaction tx(arr[i]);
            tx.apply(candidate);

            if (!validateSetting(setting) || !validateMusic(music)) {
                cout << "Некорректные данные. Выполняется откат транзакции.\n";
                tx.rollback();
                continue;
            }

            tx.commit();
            break;
        }
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

    for (int i = 0; i < n; i++) {
        arr[i]->printRow();
    }

    ofstream fout("lab8_games.txt");
    fout << left
        << setw(15) << "Название"
        << setw(12) << "Жанр"
        << setw(8) << "Год"
        << setw(15) << "Движок"
        << setw(15) << "Сеттинг"
        << setw(15) << "Музыка"
        << setw(15) << "Персонаж"
        << endl;

    for (int i = 0; i < n; i++) {
        arr[i]->saveRow(fout);
    }
    fout.close();

    SmartBox<GGame> firstBox(arr[0]);
    if (firstBox.get() != nullptr) {
        cout << "\nШаблонный SmartBox хранит игру: " << firstBox.get()->getTitle() << endl;
    }

    delete[] arr;
    pressEnter();
}