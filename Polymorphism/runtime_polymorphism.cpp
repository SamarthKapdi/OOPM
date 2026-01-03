#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Operation
{
public:
    virtual ~Operation() = default;
    virtual int apply(int x, int y) const = 0;
};

class Add : public Operation
{
public:
    int apply(int x, int y) const override { return x + y; }
};

class Multiply : public Operation
{
public:
    int apply(int x, int y) const override { return x * y; }
};

int main()
{
    vector<unique_ptr<Operation>> ops;
    ops.push_back(make_unique<Add>());
    ops.push_back(make_unique<Multiply>());

    int x = 6;
    int y = 7;
    for (const auto &op : ops)
    {
        cout << op->apply(x, y) << "\n";
    }
    return 0;
}
