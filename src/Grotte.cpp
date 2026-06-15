#include "Grotte.h"
#include "Kamp.h"
#include "Karakter.h"

// Ting
#include "Ting/Blaeser.h"
#include "Ting/Bombe.h"
#include "Ting/Forbandelse.h"
#include "Ting/Gift.h"
#include "Ting/Ildbombe.h"
#include "Ting/Kolle.h"
#include "Ting/Tordenbombe.h"

#include <iostream>

using namespace std;

Grotte::Grotte()
{
    fjender.push_back(Monster("Ulv", 1, 10));
    //fjender.push_back(Monster("Trold", 120, 15));
    //fjender.push_back(Monster("Goblin", 60, 8));

    reward = new Bombe(); // eller random senere
}

bool Grotte::gennemfoerGrotte(Karakter& spiller)
{
    Kamp kamp;

    cout << "\n=== DU GÅR IND I GROTTE ===\n";

    for (Monster& fjende : fjender)
    {
        cout << "\nEn fjende dukker op: "
             << fjende.getNavn() << "!\n";

        bool kampVundet = false;

        while (!kampVundet && spiller.harMonstreTilbage())
        {
            cout << "\nVælg dit monster:\n";
            spiller.visInventory();

            int valg;
            cin >> valg;

            Monster& valgtMonster = spiller.vaelgMonster(valg - 1);

            // Kampen
            bool sejr = kamp.kaemp(valgtMonster, fjende);

            if (!valgtMonster.erBesejret())
            {
                kampVundet = sejr;
            }
            else
            {
                cout << "\nDit monster er besejret!\n";
                cout << "Vælg et andet monster...\n";
            }
        }

        if (!spiller.harMonstreTilbage())
        {
            cout << "\nDU HAR INGEN MONSTRE TILBAGE!\n";
            return false;
        }

        cout << "\nFjende besejret!\n";
    }

    cout << "\nDU KLAREDE HELE GROTTE!\n";
    return true;
}

Ting* Grotte::getReward() const
{
    return reward;
}