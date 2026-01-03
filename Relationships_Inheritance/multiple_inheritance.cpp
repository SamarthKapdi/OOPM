#include <iostream>
#include <string>

using namespace std;

class Printable
{
public:
    virtual ~Printable() = default;
    virtual void print() const = 0;
};

class Scannable
{
public:
    virtual ~Scannable() = default;
    virtual void scan() const = 0;
};

class AllInOne : public Printable, public Scannable
{
public:
    explicit AllInOne(string model) : model_(std::move(model)) {}
    void print() const override { cout << model_ << " printing\n"; }
    void scan() const override { cout << model_ << " scanning\n"; }

private:
    string model_;
};

int main()
{
    AllInOne device("AIO-100");
    device.print();
    device.scan();
    return 0;
}
