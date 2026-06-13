#pragma once
#include <string>

using namespace std;

class Monster
{
private:
    string navn;
    int hp;
    int styrke;

public:
    Monster(string navn, int hp, int styrke);

    string getNavn() const;
    int getHp() const;
    int getStyrke() const;

    void tagSkade(int skade);
    bool erBesejret() const;
};