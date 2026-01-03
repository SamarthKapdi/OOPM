#include <iostream>

using namespace std;

template <typename T>
T add(T a, T b)
{
    return a + b;
}

int add(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    cout << "Template add<int>: " << add<int>(2, 3) << "\n";
    cout << "Template add<double>: " << add<double>(1.5, 2.25) << "\n";
    cout << "Overload add(3 ints): " << add(1, 2, 3) << "\n";
    return 0;
}
