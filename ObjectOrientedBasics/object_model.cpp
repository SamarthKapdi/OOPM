#include <iostream>
#include <string>

using namespace std;

class Box
{
public:
    Box() : label_("default")
    {
        cout << "Box()\n";
    }

    explicit Box(string label) : label_(std::move(label))
    {
        cout << "Box(string)\n";
    }

    Box(const Box &other) : label_(other.label_)
    {
        cout << "Box(copy)\n";
    }

    Box &operator=(const Box &other)
    {
        if (this != &other)
        {
            label_ = other.label_;
        }
        cout << "operator=(copy)\n";
        return *this;
    }

    ~Box()
    {
        cout << "~Box() for '" << label_ << "'\n";
    }

    void setLabel(string label) { label_ = std::move(label); }
    const string &label() const { return label_; }

private:
    string label_;
};

int main()
{
    Box stackBox("stack");
    cout << "stackBox.label = " << stackBox.label() << "\n";

    Box copied = stackBox;
    copied.setLabel("copied");
    cout << "copied.label = " << copied.label() << "\n";

    Box *heapBox = new Box("heap");
    cout << "heapBox.label = " << heapBox->label() << "\n";
    delete heapBox;

    return 0;
}
