#include "FightingPet.h"

// Default Constructor
FightingPet::FightingPet()
    : name(""), number(0), combatPower(0) {}

// Parameterized Constructor
FightingPet::FightingPet(const string& name, int number, int combatPower)
    : name(name), number(number), combatPower(combatPower) {}

// Getters
string FightingPet::getName() const {
    return name;
}

int FightingPet::getNumber() const {
    return number;
}

int FightingPet::getCombatPower() const {
    return combatPower;
}

// Setters
void FightingPet::setName(const string& name) {
    this->name = name;
}

void FightingPet::setNumber(int number) {
    this->number = number;
}

void FightingPet::setCombatPower(int combatPower) {
    this->combatPower = combatPower;
}