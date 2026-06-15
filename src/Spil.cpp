#include "Spil.h"
#include "Karakter.h"
#include "Kamp.h"
#include "Monster.h"
#include "Grotte.h"


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

Spil::Spil()
{
    karakter = nullptr;

    fjender.push_back(
        Monster("Drage", 150, 20));

    fjender.push_back(
        Monster("Trold", 120, 15));

    fjender.push_back(
        Monster("Zombie", 100, 10));

    fjender.push_back(
        Monster("Ulv", 80, 12));
    
    fjender.push_back(
        Monster("Giant", 200, 10));

    fjender.push_back(
        Monster("Vampyr", 130, 18));

    fjender.push_back(
        Monster("Goblin", 60, 10));
}

void Spil::start()
{
    hovedmenu();
}

void Spil::hovedmenu()
{
    int valg;

    do
    {
        cout << "\n1. Ny karakter\n";
        cout << "2. Afslut\n";

        cin >> valg;

        switch (valg)
        {
        case 1:
            opretKarakter();
            eventyr();
            break;

        case 2:
            cout << "Farvel\n";
            break;
        }

    } while (valg != 2);
}

void Spil::opretKarakter()
{
    string navn;

    cout << "\nKarakter navn: ";
    cin >> navn;

    delete karakter;

    karakter = new Karakter(navn);

    // Start monstre
    karakter->tilfoejMonster(
        Monster("Hest", 100, 15));

    karakter->tilfoejMonster(
        Monster("Gris", 150, 10));

    karakter->tilfoejMonster(
        Monster("Test", 10000, 10));

    // Start ting for test
    karakter->getMonstre()[2].tilfoejTing(
        new Bombe());

    karakter->getMonstre()[2].tilfoejTing(
        new Ildbombe());

    karakter->getMonstre()[2].tilfoejTing(
        new Gift());

    karakter->getMonstre()[2].tilfoejTing(
        new Forbandelse());

    karakter->getMonstre()[2].tilfoejTing(
        new Tordenbombe());

    karakter->getMonstre()[2].tilfoejTing(
        new Blaeser());

    karakter->getMonstre()[2].tilfoejTing(
        new Kolle());
    
    cout << "Dette er dit inventory:\n";
    karakter->visInventory();
}


void Spil::eventyr()
{
    Kamp kamp;
    Grotte grotte;

    while (karakter->harMonstreTilbage())
    {
        cout << "\nHvad vil du gøre?\n";
        cout << "1. Kæmp mod fjende\n";
        cout << "2. Gå i grotte\n";
        cout << "3. Vis inventory\n";
        cout << "4. Gå tilbage til hovedmenu\n";
        cout << "5. Afslut spil\n";

        int valg;
        cin >> valg;
        switch (valg)
    {
        case 1:
            break;

        case 2:
        {
            bool klar = grotte.gennemfoerGrotte(karakter->getMonstre()[0]);

            if (klar)
            {
                cout << "\nDu får en reward!\n";

                karakter->getMonstre()[0].tilfoejTing(grotte.getReward());
            }

            break;
        }
        case 3:
            karakter->visInventory();
            continue; 

        case 4:
            return;

        case 5:
            exit(0);
    }
        

        cout << "\nVælg fjende:\n";

        for (int i = 0; i < fjender.size(); i++)
        {
            cout << i + 1
                 << ". "
                 << fjender[i].getNavn() << " (HP: " << fjender[i].getHp() << ", Styrke: " << fjender[i].getStyrke() << ")"
                 << endl;
        }

        int fjendeValg;
        cin >> fjendeValg;

        Monster fjende = fjender[fjendeValg - 1];
        int originalHp = fjende.getHp();

        cout << "\nVælg monster at kæmpe med:\n";

        karakter->visInventory();

        int monsterValg;
        cin >> monsterValg;

        bool sejr = kamp.kaemp(karakter->getMonstre()[monsterValg - 1], fjende);

        while (!fjende.erBesejret() && karakter->harMonstreTilbage())
        {
            cout << "\nDit monster er besejret!\n";
            cout << "\nVil du kæmpe videre med et andet monster? (y/n): ";

            char valg;
            cin >> valg;

            if (valg != 'y' && valg != 'Y')
            {
                cout << "Du har opgivet kampen.\n";
                return;
            }

            cout << "\nVælg et andet monster:\n";
            karakter->visInventory();
            cin >> monsterValg;

            sejr = kamp.kaemp(karakter->getMonstre()[monsterValg - 1], fjende);
        }


        if (fjende.erBesejret())
        {
            cout << "\nDu har besejret " << fjende.getNavn() << "!\n";
            cout << "Vil du fange det? (y/n): ";

            char valg;
            cin >> valg;

            if (valg == 'y' || valg == 'Y')
            {
                Monster fangetMonster(
                    fjende.getNavn(),
                    originalHp,
                    fjende.getStyrke()
                );

                if (!karakter->tilfoejMonster(fangetMonster))
                {
                    cout << "\nDu har allerede 4 monstre!\n";
                    cout << "Vil du udskifte et monster? (y/n): ";

                    cin >> valg;

                    if (valg == 'y' || valg == 'Y')
                    {
                        int index;
                        cout << "Vælg hvilket monster (1-4): ";
                        karakter->visInventory();
                        cin >> index;

                        karakter->udskiftMonster(index - 1, fangetMonster);
                    }
                }
            }
        }
    }

    cout << "Alle dine monstre er besejret.\n";
}