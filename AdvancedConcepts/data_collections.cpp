#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    vector<int> v = {3, 1, 4, 1, 5};
    cout << "vector: ";
    for (int x : v)
    {
        cout << x << " ";
    }
    cout << "\n";

    set<int> uniqueValues(v.begin(), v.end());
    cout << "set(unique): ";
    for (int x : uniqueValues)
    {
        cout << x << " ";
    }
    cout << "\n";

    map<string, int> marks;
    marks["Asha"] = 90;
    marks["Karan"] = 85;
    cout << "map: Asha=" << marks["Asha"] << ", Karan=" << marks["Karan"] << "\n";

    unordered_map<string, int> freq;
    for (int x : v)
    {
        freq[to_string(x)]++;
    }
    cout << "unordered_map freq of '1' = " << freq["1"] << "\n";
    return 0;
}
