#include "Ting/Gift.h"
#include "Monster.h"
#include "Status/Poisoned.h"

#include <cstdlib>

string Gift::getNavn() const
{
    return "Gift";
}

void Gift::brug(Monster&,
                Monster& fjende)
{
    int chance = 20;

    if (fjende.harModtagetSkade())
    {
        chance = 100;
    }

    if (rand() % 100 < chance)
    {
        fjende.tilfoejStatus(
            new Poisoned(5)
        );
    }
}