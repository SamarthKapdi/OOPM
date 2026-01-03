#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee
{
public:
    Employee(int id, string name) : id_(id), name_(std::move(name)) {}
    int id() const { return id_; }
    const string &name() const { return name_; }

private:
    int id_;
    string name_;
};

class Department
{
public:
    explicit Department(string name) : name_(std::move(name)) {}

    void addEmployee(Employee *e)
    {
        employees_.push_back(e);
    }

    void list() const
    {
        cout << "Department " << name_ << ":\n";
        for (const auto *e : employees_)
        {
            cout << "  - " << e->id() << ": " << e->name() << "\n";
        }
    }

private:
    string name_;
    vector<Employee *> employees_;
};

int main()
{
    Employee e1(1, "Asha");
    Employee e2(2, "Karan");

    Department d("Engineering");
    d.addEmployee(&e1);
    d.addEmployee(&e2);
    d.list();
    return 0;
}
