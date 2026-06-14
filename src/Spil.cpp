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

    cout << "\nKarakter navn: ";
    cin >> navn;

    delete karakter;

    karakter = new Karakter(navn);

    karakter->tilfoejMonster(
        Monster("Hest", 100, 15));

    karakter->tilfoejMonster(
        Monster("Gris", 150, 10));
    
    cout << "Dette er dine start monstre:\n";
    for (const auto& monster : karakter->getMonstre())
    {
        cout << "- " << monster.getNavn() << " (HP: " << monster.getHp() << ", Styrke: " << monster.getStyrke() << ")" << endl;
    }
}


void Spil::eventyr()
{
    Kamp kamp;

    while (karakter->harMonstreTilbage())
    {
        cout << "\nHvad vil du gøre?\n";
        cout << "1. Kæmp\n";
        cout << "2. Gå tilbage til hovedmenu\n";
        cout << "3. Afslut spil\n";

        int valg;
        cin >> valg;
        if (valg == 2)
            return;
        if (valg == 3)
        {
            cout << "\nFarvel\n";
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

        for (int i = 0;
             i < karakter->getMonstre().size();
             i++)
        {
            cout << i + 1
                 << ". "
                 << karakter->getMonstre()[i].getNavn() << " (HP: " << karakter->getMonstre()[i].getHp() << ", Styrke: " << karakter->getMonstre()[i].getStyrke() << ")"
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
            cout << fjende.getNavn() << " blev fanget!\n";

            fjende = Monster(fjende.getNavn(), originalHp, fjende.getStyrke());

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