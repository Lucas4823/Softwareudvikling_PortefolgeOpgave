#include "Ting/Tordenbombe.h"
#include "Monster.h"
#include "Status/Paralyzed.h"

#include <cstdlib>

string Tordenbombe::getNavn() const
{
    return "Tordenbombe";
}

string Tordenbombe::getBeskrivelse() const
{
    return "Tordenbombe (20 skade, 50% chance for Paralyzed status (3 ture))";
}

void Tordenbombe::brug(Monster&,
                       Monster& fjende)
{
    fjende.tagSkade(20);

    if (rand() % 100 < 50)
    {
        fjende.tilfoejStatus(
            new Paralyzed(3)
        );
    }
}