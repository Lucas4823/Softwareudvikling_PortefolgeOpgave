#pragma once
#include "Status/Status.h"

class Frozen : public Status
{
public:
    Frozen(int varighed);

    string getNavn() const override;

    bool udfoer(Monster& monster) override;
};