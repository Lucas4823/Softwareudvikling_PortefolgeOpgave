#include "Ting/Gift.h"
#include "Monster.h"
#include "Status/Poisoned.h"

#include <cstdlib>

string Gift::getNavn() const
{
    return "Gift";
}

string Gift::getBeskrivelse() const
{
    return "Gift (20% chance for Poisoned status (5 ture), 100% chance hvis fjenden allerede har modtaget skade)";
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