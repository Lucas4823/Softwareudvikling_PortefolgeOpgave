#pragma once
#include <vector>
#include "Monster.h"
#include "Ting/Ting.h"

using namespace std;

class Grotte
{
private:
    vector<Monster> fjender;
    Ting* reward;

public:
    Grotte();
    bool gennemfoerGrotte(Monster& spillerMonster);

    Ting* getReward() const;
};