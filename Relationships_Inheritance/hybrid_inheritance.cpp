#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    explicit Person(string name) : name_(std::move(name)) {}
    const string &name() const { return name_; }

private:
    string name_;
};

class Student : public virtual Person
{
public:
    Student(string name, int roll) : Person(std::move(name)), roll_(roll) {}
    int roll() const { return roll_; }

private:
    int roll_;
};

class Employee : public virtual Person
{
public:
    Employee(string name, int id) : Person(std::move(name)), id_(id) {}
    int id() const { return id_; }

private:
    int id_;
};

class TeachingAssistant : public Student, public Employee
{
public:
    TeachingAssistant(string name, int roll, int id)
        : Person(name), Student(name, roll), Employee(name, id) {}
};

int main()
{
    TeachingAssistant ta("Neha", 12, 5001);
    cout << "TA name=" << ta.name() << ", roll=" << ta.roll() << ", id=" << ta.id() << "\n";
    return 0;
}
