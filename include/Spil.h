#pragma once
#include <vector>
#include "Karakter.h"
#include "Kamp.h"

using namespace std;

class Spil
{
private:
    Karakter* karakter;
    vector<Monster> fjender;

public:
    Spil();

    void start();

private:
    void hovedmenu();

    void opretKarakter();

    void eventyr();
};