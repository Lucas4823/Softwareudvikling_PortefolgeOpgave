#include "Ting/Bombe.h"
#include "Monster.h"

string Bombe::getNavn() const
{
    return "Bombe";
}

string Bombe::getBeskrivelse() const
{
    return "Bombe (20 skade)";
}

void Bombe::brug(Monster&,
                 Monster& fjende)
{
    fjende.tagSkade(20);
}