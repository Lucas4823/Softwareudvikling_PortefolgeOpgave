#include "Spil.h"
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

    cout << "Karakter navn: ";
    cin >> navn;

    delete karakter;

    karakter = new Karakter(navn);

    karakter->tilfoejMonster(
        Monster("Hest", 100, 15));

    karakter->tilfoejMonster(
        Monster("Hest", 100, 15));
}

void Spil::eventyr()
{
    Kamp kamp;

    while (karakter->harMonstreTilbage())
    {
        cout << "\nVælg fjende:\n";

        for (int i = 0; i < fjender.size(); i++)
        {
            cout << i + 1
                 << ". "
                 << fjender[i].getNavn()
                 << endl;
        }

        int fjendeValg;
        cin >> fjendeValg;

        Monster fjende =
            fjender[fjendeValg - 1];

        cout << "\nVælg monster:\n";

        for (int i = 0;
             i < karakter->getMonstre().size();
             i++)
        {
            cout << i + 1
                 << ". "
                 << karakter->getMonstre()[i].getNavn()
                 << endl;
        }

        int monsterValg;
        cin >> monsterValg;

        bool sejr =
            kamp.kaemp(
                karakter->getMonstre()[monsterValg - 1],
                fjende);

        if (sejr)
        {
            cout << "Du vandt!\n";

            if (!karakter->tilfoejMonster(fjende))
            {
                cout << "Du har allerede 4 monstre.\n";
            }
        }
        else
        {
            cout << "Dit monster blev besejret.\n";
        }
    }

    cout << "Alle dine monstre er besejret.\n";
}