#pragma once
#include <string>

using namespace std;

class Monster;

class Status
{
protected:
    int varighed;

public:
    Status(int varighed);
    virtual ~Status();

    virtual string getNavn() const = 0;

    virtual bool udfoer(Monster& monster) = 0;

    bool erFaerdig() const;
};