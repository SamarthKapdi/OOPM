#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    Student(int rollNo, string name) : rollNo_(rollNo), name_(std::move(name)) {}

    int rollNo() const { return rollNo_; }
    const string &name() const { return name_; }

    void updateName(string newName)
    {
        if (!newName.empty())
        {
            name_ = std::move(newName);
        }
    }

    void print() const
    {
        cout << "Student{ rollNo=" << rollNo_ << ", name='" << name_ << "' }\n";
    }

private:
    int rollNo_;
    string name_;
};

int main()
{
    Student s(101, "Riya");
    s.print();
    s.updateName("Riya Sharma");
    s.print();
    return 0;
}
