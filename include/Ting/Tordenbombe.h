#pragma once
#include "Ting/Ting.h"

class Tordenbombe : public Ting
{
public:
    string getNavn() const override;

    virtual string getBeskrivelse() const override;

    void brug(Monster& bruger,
              Monster& fjende) override;
};