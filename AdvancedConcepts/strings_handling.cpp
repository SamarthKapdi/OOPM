#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Enter a sentence:\n";
    string s;
    getline(cin, s);

    cout << "Length = " << s.size() << "\n";
    cout << "First 5 chars (or less) = " << s.substr(0, min<size_t>(5, s.size())) << "\n";

    const string needle = "oop";
    size_t pos = s.find(needle);
    if (pos != string::npos)
    {
        cout << "Found '" << needle << "' at index " << pos << "\n";
    }
    else
    {
        cout << "Did not find '" << needle << "'\n";
    }

    return 0;
}
