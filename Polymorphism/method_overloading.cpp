#include <iostream>
#include <string>

using namespace std;

class Printer
{
public:
    void print(int x) const { cout << "int: " << x << "\n"; }
    void print(double x) const { cout << "double: " << x << "\n"; }
    void print(const string &s) const { cout << "string: " << s << "\n"; }
};

int main()
{
    Printer p;
    p.print(10);
    p.print(3.14);
    p.print("hello");
    return 0;
}
