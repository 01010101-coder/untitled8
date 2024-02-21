#ifndef ANIMALMANAGER_H
#define ANIMALMANAGER_H

#include "Animal.h"
#include <vector>
#include <map>
#include <set>

using namespace std;

class AnimalManager {
private:
    vector<Animal*> animals;
    map<string, map<string, set<string>>> ownerAnimals; // Владелец -> Вид животного -> Клички
    map<string, map<string, int>> animalAges; // Вид животного -> Возраст

public:
    ~AnimalManager();
    void addAnimal(Animal* animal);
    void countAnimalTypesForOwners();
    void listOwnersAndNamesForType(const string& animalType);
    int countAnimalTypesWithName(const string& name);
    void showOldestAndYoungestForType();
};

#endif // ANIMALMANAGER_H