#include "Kamp.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void visKampStatus(const Monster& spiller, const Monster& fjende)
{
    cout << "\n==================== KAMP ====================\n";

    cout << "Dit monster: " << spiller.getNavn()
         << " | HP: " << spiller.getHp()
         << " | Styrke: " << spiller.getStyrke()
         << endl;

    cout << "Fjende:     " << fjende.getNavn()
         << " | HP: " << fjende.getHp()
         << " | Styrke: " << fjende.getStyrke()
         << endl;

    cout << "=============================================\n";
}

bool Kamp::kaemp(Monster& spillerMonster,
                 Monster& fjendeMonster)
{
    bool spillerStarter = rand() % 2;

    while (!spillerMonster.erBesejret()
           && !fjendeMonster.erBesejret())
    {
        visKampStatus(spillerMonster, fjendeMonster);

        if (spillerStarter)
        {
            cout << spillerMonster.getNavn()
                 << " angriber!\n";

            fjendeMonster.tagSkade(spillerMonster.getStyrke());
        }
        else
        {
            cout << fjendeMonster.getNavn()
                 << " angriber!\n";

            spillerMonster.tagSkade(fjendeMonster.getStyrke());
        }

        spillerStarter = !spillerStarter;

        cout << "\nTryk Enter for næste runde...";
        cin.ignore();
        cin.get();
    }

    visKampStatus(spillerMonster, fjendeMonster);

    return !spillerMonster.erBesejret();
}