#include <iostream>
#include <string>

using namespace std;

class Car
{
public:
    explicit Car(string model) : model_(std::move(model)) {}

    void accelerate(int deltaKmph)
    {
        if (deltaKmph < 0)
        {
            return;
        }
        speedKmph_ += deltaKmph;
    }

    void brake(int deltaKmph)
    {
        if (deltaKmph < 0)
        {
            return;
        }
        speedKmph_ -= deltaKmph;
        if (speedKmph_ < 0)
        {
            speedKmph_ = 0;
        }
    }

    int speed() const { return speedKmph_; }
    const string &model() const { return model_; }

private:
    string model_;
    int speedKmph_ = 0;
};

int main()
{
    Car c("Hatchback");
    c.accelerate(30);
    c.brake(10);

    cout << c.model() << " speed = " << c.speed() << " km/h\n";
    return 0;
}
