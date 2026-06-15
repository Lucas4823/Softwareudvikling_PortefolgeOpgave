#pragma once
#include <string>
#include <vector>

class Status;
class Ting;

using namespace std;

class Monster
{
private:
    string navn;
    int hp;
    int styrke;
    int maxHp;
    vector<Status*> statusser;
    vector<Ting*> ting;

public:
    Monster(string navn, int hp, int styrke);

    string getNavn() const;
    int getHp() const;
    int getStyrke() const;

    void tagSkade(int skade);
    bool erBesejret() const;

    void tilfoejStatus(Status* status);
    bool behandlStatusser();

    void tilfoejTing(Ting* ting);
    vector<Ting*>& getTing();
    const vector<Ting*>& getTing() const;

    bool harStatus() const;
    bool harModtagetSkade() const;

    vector<Status*>& getStatusser();
    const vector<Status*>& getStatusser() const;
};