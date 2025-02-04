#ifndef FIGHTINGPET_H
#define FIGHTINGPET_H

#include <iostream>
#include <string>

using namespace std;

class FightingPet 
{
private:

    string name; 
    int number; 
    int combatPower;

public:

    // Constructor
    FightingPet(const string& name, int number, int combatPower);

    // Getters
    string getName() const;
    int getNumber() const;
    int getCombatPower() const;
};

#endif