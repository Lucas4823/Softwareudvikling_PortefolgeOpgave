#include "Karakter.h"

Karakter::Karakter(string navn)
{
    this->navn = navn;
}

string Karakter::getNavn() const
{
    return navn;
}

bool Karakter::tilfoejMonster(Monster monster)
{
    if (monstre.size() >= 4)
        return false;

    monstre.push_back(monster);
    return true;
}

void Karakter::udskiftMonster(int indeks, Monster monster)
{
    if (indeks >= 0 && indeks < monstre.size())
    {
        monstre[indeks] = monster;
    }
}

vector<Monster>& Karakter::getMonstre()
{
    return monstre;
}

bool Karakter::harMonstreTilbage() const
{
    for (const Monster& m : monstre)
    {
        if (!m.erBesejret())
            return true;
    }

    return false;
}