#include "Ting/Forbandelse.h"
#include "Monster.h"
#include "Status/Cursed.h"

#include <cstdlib>

string Forbandelse::getNavn() const
{
    return "Forbandelse";
}

void Forbandelse::brug(Monster&,
                       Monster& fjende)
{
    int chance = 20;

    if (fjende.harStatus())
    {
        chance = 100;
    }

    if (rand() % 100 < chance)
    {
        fjende.tilfoejStatus(
            new Cursed(5)
        );
    }
}