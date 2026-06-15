#pragma once
#include <string>
#include <vector>

class Status;

using namespace std;

class Monster
{
private:
    string navn;
    int hp;
    int styrke;
    vector<Status*> statusser;

public:
    Monster(string navn, int hp, int styrke);

    string getNavn() const;
    int getHp() const;
    int getStyrke() const;

    void tagSkade(int skade);
    bool erBesejret() const;

    void tilfoejStatus(Status* status);
    bool behandlStatusser();
};