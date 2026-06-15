#include "Status/Frozen.h"
#include <iostream>

using namespace std;

Frozen::Frozen(int varighed)
    : Status(varighed)
{
}

string Frozen::getNavn() const
{
    return "Frozen";
}

bool Frozen::udfoer(Monster&)
{
    cout << "Monsteret er frozen og mister sin tur!\n";

    varighed--;

    return false;
}