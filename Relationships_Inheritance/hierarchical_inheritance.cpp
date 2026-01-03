#include <iostream>

using namespace std;

class Shape
{
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Circle : public Shape
{
public:
    explicit Circle(double radius) : r_(radius) {}
    double area() const override { return 3.141592653589793 * r_ * r_; }

private:
    double r_;
};

class Rectangle : public Shape
{
public:
    Rectangle(double w, double h) : w_(w), h_(h) {}
    double area() const override { return w_ * h_; }

private:
    double w_;
    double h_;
};

int main()
{
    Circle c(2);
    Rectangle r(3, 4);
    cout << "Circle area = " << c.area() << "\n";
    cout << "Rectangle area = " << r.area() << "\n";
    return 0;
}
