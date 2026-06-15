#include "Kamp.h"
#include "Ting/Ting.h"
#include "Status/Status.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void Kamp::visKampStatus(const Monster& spiller, const Monster& fjende)
{
    cout << "\n==================== KAMP ====================\n";

    cout << "Dit monster: " << spiller.getNavn()
         << " | HP: " << spiller.getHp()
         << " | Styrke: " << spiller.getStyrke()
         << " | Status: ";

    if (spiller.getStatusser().empty())
    {
        cout << "Ingen";
    }
    else
    {
        for (Status* s : spiller.getStatusser())
        {
            cout << s->getNavn() << " ";
        }
    }

    cout << "\n";

    cout << "Fjende:     " << fjende.getNavn()
         << " | HP: " << fjende.getHp()
         << " | Styrke: " << fjende.getStyrke()
         << " | Status: ";

    if (fjende.getStatusser().empty())
    {
        cout << "Ingen";
    }
    else
    {
        for (Status* s : fjende.getStatusser())
        {
            cout << s->getNavn() << " ";
        }
    }

    cout << "\n=============================================\n";
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

            if (!spillerMonster.behandlStatusser())
            {
                cout << "Du mister din tur pga. status!\n";
            }

            else
            {
            cout << "\nDin tur med " << spillerMonster.getNavn() << "!\n";

            cout << "1. Angrib\n";
            cout << "2. Brug ting\n";

            int valg;
            cin >> valg;

            if (valg == 1)
            {
            cout << spillerMonster.getNavn() << " angriber!\n";

            fjendeMonster.tagSkade(spillerMonster.getStyrke());
            }

            else if (valg == 2)
            {
                vector<Ting*>& ting = spillerMonster.getTing();

                if (ting.empty())
                {
                    cout << "Du har ingen ting!\n";
                }
                else
                {
                    cout << "\nVælg ting:\n";

                    for (int i = 0; i < ting.size(); i++)
                    {
                        cout << i + 1 << ". "
                            << ting[i]->getNavn()
                            << endl;
                    }

                    int tingValg;
                    cin >> tingValg;

                    if (tingValg < 1 || tingValg > ting.size())
                    {
                        cout << "Ugyldigt valg!\n";
                    }
                    else
                    {
                        ting[tingValg - 1]->brug(spillerMonster, fjendeMonster);
                    }
                }
            }
            else
            {
                cout << "Ugyldigt valg, du mister din tur!\n";}
            }
        }
        
        else
        {
            if (!fjendeMonster.behandlStatusser())
            {
                cout << fjendeMonster.getNavn()
                    << " mister sin tur!\n";
            }
            else
            {
                cout << fjendeMonster.getNavn()
                 << " angriber!\n";

                spillerMonster.tagSkade(fjendeMonster.getStyrke());
            }
        }

        spillerStarter = !spillerStarter;

        cout << "\nTryk Enter for næste runde...";
        cin.ignore();
        cin.get();
    }

    visKampStatus(spillerMonster, fjendeMonster);

    return !spillerMonster.erBesejret();
}