#include "Animal.h"

using namespace std;

Animal::Animal(const string& owner, const string& type, const string& nm, int ag)
        : ownerName(owner), animalType(type), name(nm), age(ag) {}

const string& Animal::getOwnerName() const {
    return ownerName;
}

const string& Animal::getAnimalType() const {
    return animalType;
}

const string& Animal::getName() const {
    return name;
}

int Animal::getAge() const {
    return age;
}

Dog::Dog(const string& owner, const string& name, int age)
        : Animal(owner, "dog", name, age) {}

void Dog::sound() const {
    cout << "Woof! Woof!" << endl;
}

Cat::Cat(const string& owner, const string& name, int age)
        : Animal(owner, "cat", name, age) {}

void Cat::sound() const {
    cout << "Meow! Meow!" << endl;
}

Fish::Fish(const string& owner, const string& name, int age)
        : Animal(owner, "fish", name, age) {}

void Fish::sound() const {
    cout << "Glug! Glug!" << endl;
}

Parrot::Parrot(const string& owner, const string& name, int age)
        : Animal(owner, "parrot", name, age) {}

void Parrot::sound() const {
    cout << "Polly wants a cracker!" << endl;
}

Other::Other(const string& owner, const string& type, const string& name, int age)
        : Animal(owner, type, name, age) {}

void Other::sound() const {
    cout << "I don't know what to say!" << endl;
}