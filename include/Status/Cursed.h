#pragma once
#include "Status/Status.h"

class Cursed : public Status
{
public:
    Cursed(int varighed);

    string getNavn() const override;

    bool udfoer(Monster& monster) override;
};