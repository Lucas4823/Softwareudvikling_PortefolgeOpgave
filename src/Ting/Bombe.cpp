#include "Ting/Bombe.h"
#include "Monster.h"

string Bombe::getNavn() const
{
    return "Bombe";
}

void Bombe::brug(Monster&,
                 Monster& fjende)
{
    fjende.tagSkade(10);
}