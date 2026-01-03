#include <iostream>

using namespace std;

class Shape
{
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Square : public Shape
{
public:
    explicit Square(double side) : side_(side) {}
    double area() const override { return side_ * side_; }

private:
    double side_;
};

int main()
{
    Square sq(5);
    Shape *s = &sq;
    cout << "Area via abstract base: " << s->area() << "\n";
    return 0;
}
