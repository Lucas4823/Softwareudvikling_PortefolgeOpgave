#include "Stunned.h"
#include <iostream>

using namespace std;

Stunned::Stunned()
    : Status(1)
{
}

string Stunned::getNavn() const
{
    return "Stunned";
}

bool Stunned::udfoer(Monster&)
{
    cout << "Monsteret er stunned!\n";

    varighed--;

    return false;
}