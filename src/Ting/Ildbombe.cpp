#include "Ting/Ildbombe.h"
#include "Monster.h"
#include "Status/Stunned.h"

#include <cstdlib>

string Ildbombe::getNavn() const
{
    return "Ildbombe";
}

void Ildbombe::brug(Monster&,
                    Monster& fjende)
{
    fjende.tagSkade(5);

    if (rand() % 100 < 35)
    {
        fjende.tilfoejStatus(
            new Stunned()
        );
    }
}