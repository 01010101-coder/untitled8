#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Animal.h"
#include "AnimalManager.h"

using namespace std;

int main() {
    AnimalManager manager;

    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Unable to open input file." << endl;
        return 0;
    }

    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string ownerName, animalType, name;
        int age;
        getline(ss, ownerName, ',');
        getline(ss, animalType, ',');
        getline(ss, name, ',');
        ss >> age;
        if(animalType == "собака") {
            manager.addAnimal(new Dog(ownerName, name, age));
        }
        else if(animalType == "кот") {
            manager.addAnimal(new Cat(ownerName, name, age));
        }
        else if(animalType == "рыба") {
            manager.addAnimal(new Fish(ownerName, name, age));
        }
        else if(animalType == "попугай") {
            manager.addAnimal(new Parrot(ownerName, name, age));
        }
        else {

            manager.addAnimal(new Other(ownerName, animalType, name, age));
        }
    }
    /* Пример добавления животных
    manager.addAnimal(new Dog("John", "Buddy", 3));
    manager.addAnimal(new Dog("Alice", "Max", 5));
    manager.addAnimal(new Cat("Bob", "Whiskers", 2));
    manager.addAnimal(new Fish("Eve", 1));
    manager.addAnimal(new Parrot("Charlie", "Polly", 4));
    */
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Count different animal types for each owner." << endl;
        cout << "2. List owners and names for a specific animal type." << endl;
        cout << "3. Count how many types of animals have a specific name." << endl;
        cout << "4. Show information about the oldest and youngest animal for each type." << endl;
        cout << "5. Exit." << endl;

        int choice;
        cin >> choice;

        if (choice == 5) {
            break;
        }

        switch (choice) {
            case 1:
                manager.countAnimalTypesForOwners();
                break;
            case 2: {
                string animalType;
                cout << "Enter animal type: ";
                cin >> animalType;
                manager.listOwnersAndNamesForType(animalType);
                break;
            }
            case 3: {
                string name;
                cout << "Enter name: ";
                cin >> name;
                int count = manager.countAnimalTypesWithName(name);
                cout << "Number of animal types with name " << name << ": " << count << endl;
                break;
            }
            case 4:
                manager.showOldestAndYoungestForType();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}