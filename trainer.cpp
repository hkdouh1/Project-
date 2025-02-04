#include "Trainer.h"
#include "FightingPet.h"

// Constructor
Trainer::Trainer(const string& name, int maxNumberOfFightingPets)
    : name(name), level(1), experiencePoints(0), maxNumberOfFightingPets(maxNumberOfFightingPets), currentNumberOfFightingPets(0) {
    fightingPets = new FightingPet * [maxNumberOfFightingPets]; // Allocate memory for pets

    for (int i = 0; i < maxNumberOfFightingPets; ++i) 
    {
        fightingPets[i] = nullptr; // Initialize all slots to nullptr
    }
}

// Destructor
Trainer::~Trainer() 
{
    for (int i = 0; i < currentNumberOfFightingPets; ++i) 
    {
        delete fightingPets[i]; // Free memory for each pet
    }
    delete[] fightingPets; // Free memory for the array
}

// Getters
string Trainer::getName() const 
{
    return name;
}

int Trainer::getLevel() const 
{
    return level;
}

int Trainer::getExperiencePoints() const 
{
    return experiencePoints;
}


void Trainer::addExperiencePoints(int points) 
{
    experiencePoints += points;

    while (experiencePoints >= level * 1000) 
    {
        experiencePoints -= level * 1000;
        level++;
    }
}


void Trainer::addFightingPet(FightingPet* pet)
{
    if (currentNumberOfFightingPets >= maxNumberOfFightingPets)
    {
        cout << "Error: No more slots available for fighting pets!" << endl;
        return;
    }
    fightingPets[currentNumberOfFightingPets++] = pet; // Add pet to the next slot
}