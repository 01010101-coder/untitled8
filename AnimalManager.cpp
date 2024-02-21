#include "AnimalManager.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

AnimalManager::~AnimalManager() {
    for (auto animal : animals) {
        delete animal;
    }
}



void AnimalManager::addAnimal(Animal* animal) {
    animals.push_back(animal);
    ownerAnimals[animal->getOwnerName()][animal->getAnimalType()].insert(animal->getName());
    animalAges[animal->getAnimalType()][animal->getName()] = animal->getAge();
}

void AnimalManager::countAnimalTypesForOwners() {
    for (const auto& owner : ownerAnimals) {
        cout << "Owner: " << owner.first << endl;
        for (const auto& animal : owner.second) {
            cout << "  Animal Type: " << animal.first << ", Count: " << animal.second.size() << endl;
        }
    }
}

void AnimalManager::listOwnersAndNamesForType(const string& animalType) {
    cout << "Owners and Names for " << animalType << ":" << endl;
    if (animalAges.find(animalType) != animalAges.end()) {
        for (const auto& owner : ownerAnimals) {
            if (owner.second.find(animalType) != owner.second.end()) {
                for (const auto& name : owner.second.at(animalType)) {
                    cout << "Owner: " << owner.first << ", Name: " << name << endl;
                }
            }
        }
    } else {
        cout << "No such animal type found." << endl;
    }
}

int AnimalManager::countAnimalTypesWithName(const string& name) {
    int count = 0;
    for (const auto& owner : ownerAnimals) {
        for (const auto& animal : owner.second) {
            if (animal.second.find(name) != animal.second.end()) {
                count++;
                break;
            }
        }
    }
    return count;
}

void AnimalManager::showOldestAndYoungestForType() {
    for (const auto &entry: animalAges) {
        string animalType = entry.first;
        const auto &ageMap = entry.second;
        int minAge = numeric_limits<int>::max(), maxAge = numeric_limits<int>::min();
        string youngest, oldest;
        for (const auto &animal: ageMap) {
            if (animal.second < minAge) {
                minAge = animal.second;
                youngest = animal.first;
            }
            if (animal.second > maxAge) {
                maxAge = animal.second;
                oldest = animal.first;
            }
        }
        cout << "Animal type: " << animalType << endl;
        cout << "Youngest: " << youngest << ", Age: " << minAge << endl;
        cout << "Oldest: " << oldest << ", Age: " << maxAge << endl;
    }
}