#include "Ting/Kolle.h"
#include "Monster.h"

string Kolle::getNavn() const
{
    return "Kolle";
}

string Kolle::getBeskrivelse() const
{
    return "Kolle (30 skade)";
}

void Kolle::brug(Monster&,
                 Monster& fjende)
{
    fjende.tagSkade(30);
}