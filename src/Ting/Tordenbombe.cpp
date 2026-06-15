#include "Ting/Tordenbombe.h"
#include "Monster.h"
#include "Status/Paralyzed.h"

#include <cstdlib>

string Tordenbombe::getNavn() const
{
    return "Tordenbombe";
}

void Tordenbombe::brug(Monster&,
                       Monster& fjende)
{
    fjende.tagSkade(10);

    if (rand() % 100 < 50)
    {
        fjende.tilfoejStatus(
            new Paralyzed(3)
        );
    }
}