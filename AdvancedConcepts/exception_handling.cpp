#include <iostream>
#include <stdexcept>

using namespace std;

class NegativeNumberError : public runtime_error
{
public:
    explicit NegativeNumberError(const string &msg) : runtime_error(msg) {}
};

int safeSqrtInt(int x)
{
    if (x < 0)
    {
        throw NegativeNumberError("sqrt not defined for negative numbers");
    }
    int r = 0;
    while ((r + 1) * (r + 1) <= x)
    {
        r++;
    }
    return r;
}

int main()
{
    try
    {
        cout << "safeSqrtInt(10) = " << safeSqrtInt(10) << "\n";
        cout << "safeSqrtInt(-1) = " << safeSqrtInt(-1) << "\n";
    }
    catch (const NegativeNumberError &e)
    {
        cout << "Caught NegativeNumberError: " << e.what() << "\n";
    }
    catch (const exception &e)
    {
        cout << "Caught exception: " << e.what() << "\n";
    }
    return 0;
}
