#include "Status/Paralyzed.h"

#include <cstdlib>
#include <iostream>

using namespace std;

Paralyzed::Paralyzed(int varighed)
    : Status(varighed)
{
}

string Paralyzed::getNavn() const
{
    return "Paralyzed";
}

bool Paralyzed::udfoer(Monster&)
{
    varighed--;

    if (rand() % 100 < 50)
    {
        cout << "Monsteret er paralyzed!\n";
        return false;
    }

    return true;
}