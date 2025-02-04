#include <iostream>
#include "Trainer.h"
#include "FightingPet.h"

using namespace std;

int main() 
{
    // Creating a trainer (me lol)
    Trainer hassan("Hassan", 3);

    
    cout << "Trainer Name: " << hassan.getName() << endl;
    cout << "Level: " << hassan.getLevel() << endl;
    cout << "XP: " << hassan.getExperiencePoints() << endl;
    cout << endl;

    
    cout << "Adding 1500 XP..." << endl;

    hassan.addExperiencePoints(1500);

    cout << "New Level: " << hassan.getLevel() << endl;
    cout << "Remaining XP: " << hassan.getExperiencePoints() << endl;
    cout << endl;

    // Creating my fighting pets
    FightingPet* charger = new FightingPet("Charger", 1, 500);
    FightingPet* flapjack = new FightingPet("Flapjack", 2, 450);
    FightingPet* jumbo = new FightingPet("Jumbo", 3, 480);

    
    cout << "Adding Fighting Pets..." << endl;

    hassan.addFightingPet(charger);
    cout << "Added " << charger->getName() << " to the team." << endl;

    hassan.addFightingPet(flapjack);
    cout << "Added " << flapjack->getName() << " to the team." << endl;

    hassan.addFightingPet(jumbo);
    cout << "Added " << jumbo->getName() << " to the team." << endl;

    // trying to add another pet but would fail bc slot is 3 max
    FightingPet* thunder = new FightingPet("Thunder", 4, 600);
    hassan.addFightingPet(thunder);

    return 0;
}