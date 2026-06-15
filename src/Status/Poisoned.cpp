#include "Status/Poisoned.h"
#include "Monster.h"
#include <iostream>

using namespace std;

Poisoned::Poisoned(int varighed)
    : Status(varighed)
{
}

string Poisoned::getNavn() const
{
    return "Poisoned";
}

bool Poisoned::udfoer(Monster& monster)
{
    cout << monster.getNavn()
         << " tager 5 poison damage!\n";

    monster.tagSkade(5);

    varighed--;

    return true;
}