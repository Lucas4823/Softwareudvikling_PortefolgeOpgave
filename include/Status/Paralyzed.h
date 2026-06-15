#pragma once
#include "Status/Status.h"

class Paralyzed : public Status
{
public:
    Paralyzed(int varighed);

    string getNavn() const override;

    bool udfoer(Monster& monster) override;
};