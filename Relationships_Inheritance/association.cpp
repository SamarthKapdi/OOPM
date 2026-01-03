#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    explicit Student(string name) : name_(std::move(name)) {}
    const string &name() const { return name_; }

private:
    string name_;
};

class Teacher
{
public:
    explicit Teacher(string name) : name_(std::move(name)) {}

    void teach(const Student &s) const
    {
        cout << name_ << " teaches " << s.name() << "\n";
    }

private:
    string name_;
};

int main()
{
    Teacher t("Mr. Rao");
    Student s("Ishita");
    t.teach(s);
    return 0;
}
