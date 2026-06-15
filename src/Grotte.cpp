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

Grotte::Grotte(const Karakter& spiller)
{
    float hp = spiller.gennemsnitHp();
    float str = spiller.gennemsnitStyrke();

    fjender.clear();

    fjender.push_back(Monster("Goblin", hp * 0.4, str * 0.4));

    fjender.push_back(Monster("Ork", hp * 0.6, str * 0.6));

    fjender.push_back(Monster("Boss", hp * 1, str * 1));
    reward = nullptr;
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

    cout << "\nDU KLAREDE HELE GROTTEN!\n";
    reward = genererReward();

    return true;
}

Ting* Grotte::getReward() const
{
    return reward;
}

Ting* Grotte::genererReward() const
{
    int r = rand() % 7;

    switch (r)
    {
        case 0:
            return new Bombe();

        case 1:
            return new Ildbombe();

        case 2:
            return new Gift();

        case 3:
            return new Forbandelse();

        case 4:
            return new Tordenbombe();

        case 5:
            return new Kolle();

        case 6:
            return new Blaeser();
    }

    return new Bombe(); // fallback
}