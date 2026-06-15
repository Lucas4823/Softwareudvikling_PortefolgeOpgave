#pragma once
#include "Status.h"

class Stunned : public Status
{
public:
    Stunned();

    string getNavn() const override;

    bool udfoer(Monster& monster) override;
};