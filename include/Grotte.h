#pragma once
#include <vector>
#include "Monster.h"
#include "Ting/Ting.h"
#include "Karakter.h"

using namespace std;

class Grotte
{
private:
    vector<Monster> fjender;
    Ting* reward;

public:
    Grotte(const Karakter& spiller);
    bool gennemfoerGrotte(Karakter& spiller);

    Ting* getReward() const;

    Ting* genererReward() const;

};