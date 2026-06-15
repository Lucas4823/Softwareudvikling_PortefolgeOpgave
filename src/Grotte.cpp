#include "Grotte.h"
#include "Kamp.h"

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
    fjender.push_back(Monster("Ulv", 80, 10));
    fjender.push_back(Monster("Trold", 120, 15));
    fjender.push_back(Monster("Goblin", 60, 8));

    reward = new Bombe(); // eller random senere
}

bool Grotte::gennemfoerGrotte(Monster& spillerMonster)
{
    Kamp kamp;

    cout << "\n=== DU ENTRER GROTTE ===\n";

    for (Monster& fjende : fjender)
    {
        cout << "\nNy fjende dukker op: "
             << fjende.getNavn() << "!\n";

        bool vundet = kamp.kaemp(spillerMonster, fjende);

        if (!vundet)
        {
            cout << "\nDU TABTE GROTTE!\n";
            return false;
        }
    }

    cout << "\nDU HAR KLARET GROTTE!\n";

    return true;
}

Ting* Grotte::getReward() const
{
    return reward;
}