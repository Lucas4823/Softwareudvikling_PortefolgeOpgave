#include "Status/Cursed.h"
#include "Monster.h"
#include <iostream>

using namespace std;

Cursed::Cursed(int varighed)
    : Status(varighed)
{
}

string Cursed::getNavn() const
{
    return "Cursed";
}

bool Cursed::udfoer(Monster& monster)
{
    cout << monster.getNavn()
         << " er cursed og tager recoil skade!\n";

    monster.tagSkade(5);

    varighed--;   // fra base class

    return true;
}