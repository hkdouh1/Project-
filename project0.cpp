#include <iostream>
#include "Trainer.h"
#include "FightingPet.h"

using namespace std;

int main() {
    // Create a Trainer object
    Trainer hassan("Hassan", 3);

    // Display initial trainer details
    cout << "Trainer Name: " << hassan.getName() << endl;
    cout << "Max Number of Fighting Pets: " << hassan.getMaxNumberOfFightingPets() << endl;
    cout << "Current Level: " << hassan.getLevel() << endl;
    cout << "Experience Points: " << hassan.getExperiencePoints() << endl;
    cout << endl;

    // Add experience points
    cout << "Adding Experience Points..." << endl;
    hassan.addExperiencePoints(1500);
    cout << "Added 1500 experience points." << endl;
    cout << "New Level: " << hassan.getLevel() << endl;
    cout << "Remaining Experience Points: " << hassan.getExperiencePoints() << endl;
    cout << endl;

    // Create some FightingPet objects
    FightingPet* charger = new FightingPet("Charger", 1, 500);
    FightingPet* flapjack = new FightingPet("Flapjack", 2, 450);
    FightingPet* jumbo = new FightingPet("Jumbo", 3, 480);

    // Add fighting pets to the trainer
    cout << "Adding Fighting Pets..." << endl;
    try {
        hassan.addFightingPet(charger);
        cout << "Added " << charger->getName() << " to the team." << endl;

        hassan.addFightingPet(flapjack);
        cout << "Added " << flapjack->getName() << " to the team." << endl;

        hassan.addFightingPet(jumbo);
        cout << "Added " << jumbo->getName() << " to the team." << endl;

        // Try adding another pet (should throw an exception)
        FightingPet* thunder = new FightingPet("Thunder", 4, 600);
        hassan.addFightingPet(thunder);
        cout << "Added " << thunder->getName() << " to the team." << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    cout << endl;

    // Increase storage for fighting pets
    cout << "Increasing storage for fighting pets..." << endl;
    hassan.addMoreFightingPetStorage();
    cout << "New Max Number of Fighting Pets: " << hassan.getMaxNumberOfFightingPets() << endl;

    // Add another pet after increasing storage
    try {
        FightingPet* thunder = new FightingPet("Thunder", 4, 600);
        hassan.addFightingPet(thunder);
        cout << "Added " << thunder->getName() << " to the team." << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    cout << endl;

    // Final trainer details
    cout << "Final Trainer Details:" << endl;
    cout << "Name: " << hassan.getName() << endl;
    cout << "Level: " << hassan.getLevel() << endl;
    cout << "Experience Points: " << hassan.getExperiencePoints() << endl;
    cout << "Max Number of Fighting Pets: " << hassan.getMaxNumberOfFightingPets() << endl;

    return 0;
}