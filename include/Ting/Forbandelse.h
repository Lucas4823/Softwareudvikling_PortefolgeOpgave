#pragma once
#include "Ting/Ting.h"

class Forbandelse : public Ting
{
public:
    string getNavn() const override;

    void brug(Monster& bruger,
              Monster& fjende) override;
};