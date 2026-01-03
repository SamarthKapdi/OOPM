#include <iostream>
#include <string>

using namespace std;

double rectangleArea_procedural(double width, double height)
{
    return width * height;
}

class Rectangle
{
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}

    double area() const
    {
        return width_ * height_;
    }

    void resize(double newWidth, double newHeight)
    {
        width_ = newWidth;
        height_ = newHeight;
    }

private:
    double width_;
    double height_;
};

int main()
{
    cout << "Procedural style: area = " << rectangleArea_procedural(4, 3) << "\n";

    Rectangle r(4, 3);
    cout << "OOP style: area = " << r.area() << "\n";
    r.resize(10, 2);
    cout << "After resize: area = " << r.area() << "\n";

    return 0;
}
