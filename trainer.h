#ifndef TRAINER_H
#define TRAINER_H

#include <iostream>
#include <string>

using namespace std;

class FightingPet;

class Trainer 
{
private:

    string name;
    int level;
    int experiencePoints; 
    int maxNumberOfFightingPets;
    FightingPet** fightingPets; 
    int currentNumberOfFightingPets;

public:

    // Constructor
    Trainer(const string& name, int maxNumberOfFightingPets);

    // Destructor
    ~Trainer();

    // Getters
    string getName() const;
    int getLevel() const;
    int getExperiencePoints() const;

    // Methods
    void addExperiencePoints(int points); // Add experience points
    void addFightingPet(FightingPet* pet); // Add a pet to the team
};

#endif