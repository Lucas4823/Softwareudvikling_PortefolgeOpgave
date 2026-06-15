#pragma once
#include "Status/Status.h"

class Poisoned : public Status
{
public:
    Poisoned(int varighed);

    string getNavn() const override;

    bool udfoer(Monster& monster) override;
};