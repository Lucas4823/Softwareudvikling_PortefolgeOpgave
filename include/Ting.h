#pragma once
#include <string>

using namespace std;

class Monster;

class Ting
{
public:
    virtual ~Ting();

    virtual string getNavn() const = 0;

    virtual void brug(Monster& bruger,
                      Monster& fjende) = 0;
};