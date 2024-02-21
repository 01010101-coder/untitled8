#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <map>
#include <set>

using namespace std;

class Animal {
protected:
    string ownerName;
    string animalType;
    string name; // Кличка
    int age;

public:
    Animal(const string& owner, const string& type, const string& nm, int ag);
    virtual void sound() const = 0;
    const string& getOwnerName() const;
    const string& getAnimalType() const;
    const string& getName() const;
    int getAge() const;
};

class Dog : public Animal {
public:
    Dog(const string& owner, const string& name, int age);
    void sound() const override;
};

class Cat : public Animal {
public:
    Cat(const string& owner, const string& name, int age);
    void sound() const override;
};

class Fish : public Animal {
public:
    Fish(const string& owner, const string& name, int age);
    void sound() const override;
};

class Parrot : public Animal {
public:
    Parrot(const string& owner, const string& name, int age);
    void sound() const override;
};

class Other : public Animal {
private:
    string otherType;
public:
    Other(const string& owner, const string& type, const string& name, int age);
    const string& getOtherType() const {
        return otherType;
    }
    void setOtherType(const string el)
    {
        otherType = el;
    }
    void sound() const override;
};

#endif // ANIMAL_H