#include "Monster.h"
#include "Status/Status.h"
#include "Ting/Ting.h"

Monster::Monster(string navn, int hp, int styrke)
{
    this->navn = navn;
    this->hp = hp;
    this->maxHp = hp;
    this->styrke = styrke;
    this->statusser = vector<Status*>();
    this->ting = vector<Ting*>();
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

void Monster::tilfoejTing(Ting* ting)
{
    this->ting.push_back(ting);
}

vector<Ting*>& Monster::getTing()
{
    return ting;
}

const vector<Ting*>& Monster::getTing() const
{
    return ting;
}

bool Monster::harStatus() const
{
    return !statusser.empty();
}

bool Monster::harModtagetSkade() const
{
    return hp < maxHp;
}

vector<Status*>& Monster::getStatusser()
{
    return statusser;
}

const vector<Status*>& Monster::getStatusser() const
{
    return statusser;
}