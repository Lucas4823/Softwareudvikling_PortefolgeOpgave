#include "Status/Cursed.h"

Cursed::Cursed(int varighed)
    : Status(varighed)
{
}

string Cursed::getNavn() const
{
    return "Cursed";
}

bool Cursed::udfoer(Monster&)
{
    varighed--;

    return true;
}