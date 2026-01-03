#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Animal
{
public:
    explicit Animal(string name) : name_(std::move(name)) {}
    virtual ~Animal() = default;

    virtual void speak() const
    {
        cout << name_ << " makes a sound\n";
    }

protected:
    string name_;
};

class Dog final : public Animal
{
public:
    explicit Dog(string name) : Animal(std::move(name)) {}
    void speak() const override
    {
        cout << name_ << " barks\n";
    }
};

class Counter
{
public:
    void increment() { value_++; }
    int value() const { return value_; }

private:
    int value_ = 0;
};

int main()
{
    Counter c;
    c.increment();
    c.increment();
    cout << "Encapsulation (private state): value = " << c.value() << "\n";

    unique_ptr<Animal> a = make_unique<Dog>("Buddy");
    cout << "Inheritance + polymorphism: ";
    a->speak();

    return 0;
}
