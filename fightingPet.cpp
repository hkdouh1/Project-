#include "FightingPet.h"

// Constructor
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