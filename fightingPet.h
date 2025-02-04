#ifndef FIGHTINGPET_H
#define FIGHTINGPET_H

#include <iostream>
#include <string>

using namespace std;

class FightingPet {
private:
    string name; // Private attribute for pet's name
    int number; // Private attribute for pet's number
    int combatPower; // Private attribute for pet's combat power

public:
    // Constructors
    FightingPet(); // Default constructor
    FightingPet(const string& name, int number, int combatPower); // Parameterized constructor

    // Getters
    string getName() const; // Get pet's name
    int getNumber() const; // Get pet's number
    int getCombatPower() const; // Get pet's combat power

    // Setters
    void setName(const string& name); // Set pet's name
    void setNumber(int number); // Set pet's number
    void setCombatPower(int combatPower); // Set pet's combat power
};

#endif