#include "Karakter.h"
#include "Ting/Ting.h"
#include <iostream>

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

void Karakter::visInventory() const
{

    cout << "\n=========== INVENTORY ===========\n";
    cout << "Karakter: " << navn << "\n";
    cout << "Monstre:\n";

    if (monstre.empty())
    {
        cout << "Du har ingen monstre endnu.\n";
    }
    else
    {
        for (int i = 0; i < monstre.size(); i++)
        {
            cout << i + 1 << ". "
                 << monstre[i].getNavn()
                 << " | HP: " << monstre[i].getHp()
                 << " | STY: " << monstre[i].getStyrke()
                 << " | Ting: ";

            if (monstre[i].getTing().empty())
            {
                cout << "Ingen";
            }
            else
            {
                for (Ting* ting : monstre[i].getTing())
                {
                    cout << "[" << ting->getNavn() << "] ";
                }
            }
            
            if (monstre[i].erBesejret())
            {
                cout << " (DEFEATED)";
            }

            cout << "\n";
        }
    }

    cout << "=================================\n";
}