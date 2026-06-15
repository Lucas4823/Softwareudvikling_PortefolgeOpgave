#pragma once
#include <string>
#include <vector>
#include "Monster.h"

using namespace std;

class Karakter
{
private:
    string navn;
    vector<Monster> monstre;

public:
    Karakter(string navn);

    string getNavn() const;

    bool tilfoejMonster(Monster monster);

    void udskiftMonster(int indeks, Monster monster);

    vector<Monster>& getMonstre();

    bool harMonstreTilbage() const;

    void visInventory() const;

    Monster& vaelgMonster(int index);
};