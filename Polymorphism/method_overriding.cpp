#include <iostream>

using namespace std;

class Base
{
public:
    virtual ~Base() = default;
    virtual void show() const { cout << "Base::show\n"; }
};

class Derived : public Base
{
public:
    void show() const override { cout << "Derived::show\n"; }
};

int main()
{
    Base b;
    Derived d;

    b.show();
    d.show();

    Base *p = &d;
    p->show();

    return 0;
}
