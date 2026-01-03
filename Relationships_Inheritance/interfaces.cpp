#include <iostream>
#include <string>

using namespace std;

struct ISerializable
{
    virtual ~ISerializable() = default;
    virtual string serialize() const = 0;
};

class Point : public ISerializable
{
public:
    Point(int x, int y) : x_(x), y_(y) {}
    string serialize() const override
    {
        return "{" + to_string(x_) + "," + to_string(y_) + "}";
    }

private:
    int x_;
    int y_;
};

int main()
{
    Point p(3, 4);
    ISerializable *s = &p;
    cout << "Serialized point = " << s->serialize() << "\n";
    return 0;
}
