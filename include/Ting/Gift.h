#pragma once
#include "Ting/Ting.h"

class Gift : public Ting
{
public:
    string getNavn() const override;

    void brug(Monster& bruger,
              Monster& fjende) override;
};