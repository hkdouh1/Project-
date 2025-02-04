#include "Trainer.h"
#include "FightingPet.h"

// Constructor
Trainer::Trainer(const string& name, int maxNumberOfFightingPets)
    : name(name), level(1), experiencePoints(0), maxNumberOfFightingPets(maxNumberOfFightingPets), currentNumberOfFightingPets(0) {
    fightingPets = new FightingPet * [maxNumberOfFightingPets];
    for (int i = 0; i < maxNumberOfFightingPets; ++i) {
        fightingPets[i] = nullptr;
    }
}

// Destructor
Trainer::~Trainer() {
    for (int i = 0; i < currentNumberOfFightingPets; ++i) {
        delete fightingPets[i]; // Free memory for each FightingPet
    }
    delete[] fightingPets; // Free memory for the array
}

// Copy Constructor
Trainer::Trainer(const Trainer& other)
    : name(other.name), level(other.level), experiencePoints(other.experiencePoints),
    maxNumberOfFightingPets(other.maxNumberOfFightingPets), currentNumberOfFightingPets(other.currentNumberOfFightingPets) {
    fightingPets = new FightingPet * [maxNumberOfFightingPets];
    for (int i = 0; i < currentNumberOfFightingPets; ++i) {
        fightingPets[i] = new FightingPet(*other.fightingPets[i]); // Deep copy each FightingPet
    }
}

// Copy Assignment Operator
Trainer& Trainer::operator=(const Trainer& other) {
    if (this == &other) {
        return *this; // Self-assignment check
    }

    // Free existing resources
    for (int i = 0; i < currentNumberOfFightingPets; ++i) {
        delete fightingPets[i];
    }
    delete[] fightingPets;

    // Copy attributes
    name = other.name;
    level = other.level;
    experiencePoints = other.experiencePoints;
    maxNumberOfFightingPets = other.maxNumberOfFightingPets;
    currentNumberOfFightingPets = other.currentNumberOfFightingPets;

    // Allocate new resources
    fightingPets = new FightingPet * [maxNumberOfFightingPets];
    for (int i = 0; i < currentNumberOfFightingPets; ++i) {
        fightingPets[i] = new FightingPet(*other.fightingPets[i]); // Deep copy each FightingPet
    }

    return *this;
}

// Getters
string Trainer::getName() const {
    return name;
}

int Trainer::getMaxNumberOfFightingPets() const {
    return maxNumberOfFightingPets;
}

int Trainer::getLevel() const {
    return level;
}

int Trainer::getExperiencePoints() const {
    return experiencePoints;
}

// Setters
void Trainer::setName(const string& name) {
    this->name = name;
}

void Trainer::setMaxNumberOfFightingPets(int maxNumberOfFightingPets) {
    this->maxNumberOfFightingPets = maxNumberOfFightingPets;
}

// Method to add experience points
void Trainer::addExperiencePoints(int points) {
    experiencePoints += points;
    while (experiencePoints >= level * 1000) { // Level up logic
        experiencePoints -= level * 1000;
        level++;
    }
}

// Method to add a fighting pet
void Trainer::addFightingPet(FightingPet* pet) {
    if (currentNumberOfFightingPets >= maxNumberOfFightingPets) {
        throw runtime_error("No more slots available for fighting pets!");
    }
    fightingPets[currentNumberOfFightingPets++] = pet;
}

// Method to increase storage for fighting pets
void Trainer::addMoreFightingPetStorage() {
    int newMax = maxNumberOfFightingPets * 2; // Double the size
    FightingPet** newFightingPets = new FightingPet * [newMax];

    // Copy existing pets to the new array
    for (int i = 0; i < currentNumberOfFightingPets; ++i) {
        newFightingPets[i] = fightingPets[i];
    }

    // Initialize the rest of the slots to nullptr
    for (int i = currentNumberOfFightingPets; i < newMax; ++i) {
        newFightingPets[i] = nullptr;
    }

    // Free the old array
    delete[] fightingPets;

    // Update attributes
    fightingPets = newFightingPets;
    maxNumberOfFightingPets = newMax;
}
