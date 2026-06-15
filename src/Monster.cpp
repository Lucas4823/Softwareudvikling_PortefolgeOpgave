#include "Monster.h"
#include "Status.h"

Monster::Monster(string navn, int hp, int styrke)
{
    this->navn = navn;
    this->hp = hp;
    this->styrke = styrke;
    this->statusser = vector<Status*>();
}

string Monster::getNavn() const
{
    return navn;
}

int Monster::getHp() const
{
    return hp;
}

int Monster::getStyrke() const
{
    return styrke;
}

void Monster::tagSkade(int skade)
{
    hp -= skade;

    if (hp < 0)
        hp = 0;
}

bool Monster::erBesejret() const
{
    return hp <= 0;
}

void Monster::tilfoejStatus(Status* status)
{
    statusser.push_back(status);
}

bool Monster::behandlStatusser()
{
    bool maaHandle = true;

    for (int i = 0; i < statusser.size();)
    {
        bool resultat =
            statusser[i]->udfoer(*this);

        if (!resultat)
        {
            maaHandle = false;
        }

        if (statusser[i]->erFaerdig())
        {
            delete statusser[i];

            statusser.erase(
                statusser.begin() + i
            );
        }
        else
        {
            i++;
        }
    }

    return maaHandle;
}