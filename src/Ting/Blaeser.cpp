#include "Ting/Blaeser.h"
#include "Monster.h"
#include "Status/Frozen.h"

#include <cstdlib>

string Blaeser::getNavn() const
{
    return "Blæser";
}

void Blaeser::brug(Monster&,
                   Monster& fjende)
{
    if (rand() % 100 < 80)
    {
        int ture = rand() % 2 + 1;

        fjende.tilfoejStatus(
            new Frozen(ture)
        );
    }
}