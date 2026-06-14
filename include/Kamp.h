#pragma once
#include "Monster.h"

class Kamp
{
public:
    bool kaemp(Monster& spiller, Monster& fjende);

private:
    void visKampStatus(const Monster& spiller,
                       const Monster& fjende);
};