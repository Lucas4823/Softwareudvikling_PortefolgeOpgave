#include "Spil.h"
#include "Karakter.h"
#include "Ting/Bombe.h"
#include "Ting/Ildbombe.h"
#include "Ting/Gift.h"
#include "Ting/Forbandelse.h"
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
        Monster("Giant", 200, 25));

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

    karakter->tilfoejMonster(
        Monster("Hest", 100, 15));

    karakter->tilfoejMonster(
        Monster("Gris", 150, 10));

    karakter->getMonstre()[0].tilfoejTing(
        new Bombe());

    karakter->getMonstre()[0].tilfoejTing(
        new Ildbombe());

    karakter->getMonstre()[1].tilfoejTing(
        new Gift());

    
    cout << "Dette er dit inventory:\n";
    karakter->visInventory();
}


void Spil::eventyr()
{
    Kamp kamp;

    while (karakter->harMonstreTilbage())
    {
        cout << "\nHvad vil du gøre?\n";
        cout << "1. Kæmp\n";
        cout << "2. Vis inventory\n";
        cout << "3. Gå tilbage til hovedmenu\n";
        cout << "4. Afslut spil\n";

        int valg;
        cin >> valg;
        switch (valg)
    {
        case 1:
            break;

        case 2:
            karakter->visInventory();
            continue; 

        case 3:
            return;

        case 4:
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