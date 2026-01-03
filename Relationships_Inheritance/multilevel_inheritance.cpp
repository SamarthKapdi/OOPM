#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    explicit Animal(string name) : name_(std::move(name)) {}
    const string &name() const { return name_; }

private:
    string name_;
};

class Mammal : public Animal
{
public:
    Mammal(string name, bool warmBlooded) : Animal(std::move(name)), warmBlooded_(warmBlooded) {}
    bool warmBlooded() const { return warmBlooded_; }

private:
    bool warmBlooded_;
};

class Dog : public Mammal
{
public:
    Dog(string name, string breed) : Mammal(std::move(name), true), breed_(std::move(breed)) {}
    const string &breed() const { return breed_; }

private:
    string breed_;
};

int main()
{
    Dog d("Max", "Labrador");
    cout << d.name() << " is a " << d.breed() << " (warmBlooded=" << (d.warmBlooded() ? "yes" : "no") << ")\n";
    return 0;
}
