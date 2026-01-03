#include <iostream>
#include <string>

using namespace std;

class Widget
{
public:
    explicit Widget(string name) : name_(std::move(name))
    {
        createdCount_++;
    }

    static int createdCount() { return createdCount_; }
    const string &name() const { return name_; }

private:
    string name_;
    static int createdCount_;
};

int Widget::createdCount_ = 0;

int main()
{
    Widget a("A");
    Widget b("B");
    Widget c("C");
    cout << "Widgets created = " << Widget::createdCount() << "\n";
    cout << "Example widget: " << a.name() << "\n";
    return 0;
}
