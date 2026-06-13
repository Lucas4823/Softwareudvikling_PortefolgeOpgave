#include "Monster.h"

Monster::Monster(string navn, int hp, int styrke)
{
    this->navn = navn;
    this->hp = hp;
    this->styrke = styrke;
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