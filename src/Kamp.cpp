#include "Kamp.h"
#include <cstdlib>

bool Kamp::kaemp(Monster& spillerMonster,
                 Monster& fjendeMonster)
{
    bool spillerStarter = rand() % 2; // Tilfældig beslutning om hvem der starter

    while (!spillerMonster.erBesejret()
           && !fjendeMonster.erBesejret())
    {
        if (spillerStarter)
        {
            fjendeMonster.tagSkade(
                spillerMonster.getStyrke());

            if (!fjendeMonster.erBesejret())
            {
                spillerMonster.tagSkade(
                    fjendeMonster.getStyrke());
            }
        }
        else
        {
            spillerMonster.tagSkade(
                fjendeMonster.getStyrke());

            if (!spillerMonster.erBesejret())
            {
                fjendeMonster.tagSkade(
                    spillerMonster.getStyrke());
            }
        }
    }

    return !spillerMonster.erBesejret();
}