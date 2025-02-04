#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <string>

using namespace std;

class FightingPet;

class Trainer {
private:
    string name; // Private attribute for trainer's name
    int level; // Private attribute for trainer's level
    int experiencePoints; // Private attribute for experience points
    int maxNumberOfFightingPets; // Private attribute for maximum number of fighting pets
    FightingPet** fightingPets; // Dynamic array of FightingPet pointers
    int currentNumberOfFightingPets; // Tracks the current number of fighting pets

public:
    // Constructor
    Trainer(const string& name, int maxNumberOfFightingPets);

    // Destructor
    ~Trainer();

    // Copy Constructor
    Trainer(const Trainer& other);

    // Copy Assignment Operator
    Trainer& operator=(const Trainer& other);

    // Getters
    string getName() const; // Get trainer's name
    int getMaxNumberOfFightingPets() const; // Get maximum number of fighting pets
    int getLevel() const; // Get trainer's level
    int getExperiencePoints() const; // Get trainer's experience points

    // Setters
    void setName(const string& name); // Set trainer's name
    void setMaxNumberOfFightingPets(int maxNumberOfFightingPets); // Set maximum number of fighting pets

    // Methods
    void addExperiencePoints(int points); // Add experience points and handle leveling up
    void addFightingPet(FightingPet* pet); // Add a fighting pet to the array
    void addMoreFightingPetStorage(); // Increase the size of the fighting pet array
};

#endif