#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    explicit Person(string name) : name_(std::move(name)) {}

    const string &name() const { return name_; }

protected:
    void setName(string newName) { name_ = std::move(newName); }

private:
    string name_;
};

class Employee : public Person
{
public:
    Employee(string name, int id) : Person(std::move(name)), id_(id) {}

    void rename(string newName)
    {
        setName(std::move(newName));
    }

    int id() const { return id_; }

private:
    int id_;
};

int main()
{
    Employee e("Aman", 7);
    cout << "Employee: " << e.name() << ", id=" << e.id() << "\n";
    e.rename("Aman Verma");
    cout << "Renamed: " << e.name() << "\n";
    return 0;
}
