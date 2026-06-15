#include "Ting/Kolle.h"
#include "Monster.h"

string Kolle::getNavn() const
{
    return "Kolle";
}

void Kolle::brug(Monster&,
                 Monster& fjende)
{
    fjende.tagSkade(30);
}