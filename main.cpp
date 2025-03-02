#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Animal {
protected:
    string name;
    int age;
public:
    Animal(string n, int a) : name(n), age(a) {}
    virtual void makeSound() {
        cout << name << " ovoz chiqarmoqda!" << endl;
    }
    virtual void showInfo() {
        cout << "Hayvon: " << name << ", Yosh: " << age << endl;
    }
};


class Mammal : public Animal {
public:
    Mammal(string n, int a) : Animal(n, a) {}
    void makeSound() override {
        cout << name << " mammal tovush chiqarmoqda!" << endl;
    }
};


class Bird : public Animal {
public:
    Bird(string n, int a) : Animal(n, a) {}
    void makeSound() override {
        cout << name << " chirillamoqda!" << endl;
    }
};

class ZooKeeper {
private:
    string name;
public:
    ZooKeeper(string n) : name(n) {}
    void feedAnimal(Animal &a) {
      //  cout << name << " " << a.name << "ni ovqatlantirmoqda!" << endl;
    }
};

class Zoo {
private:
    vector<Animal*> animals;
public:
    void addAnimal(Animal* a) {
        animals.push_back(a);
    }
    void showAllAnimals() {
        cout << "Hayvonot bog'idagi hayvonlar:" << endl;
        for (Animal* a : animals) {
            a->showInfo();
            a->makeSound();
        }
    }
};

int main() {
    srand(time(0));

    Mammal tiger("Sher", 5);
    Bird parrot("To'tiqush", 2);


    Zoo myZoo;
    myZoo.addAnimal(&tiger);
    myZoo.addAnimal(&parrot);

    ZooKeeper keeper("Ali");
    keeper.feedAnimal(tiger);
    keeper.feedAnimal(parrot);

    myZoo.showAllAnimals();

    return 0;
}
