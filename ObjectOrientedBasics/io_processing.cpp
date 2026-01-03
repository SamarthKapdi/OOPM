#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    cout << "Enter a line containing words and numbers (example: 'alice 10 bob 20'):\n";
    string line;
    getline(cin, line);

    istringstream in(line);
    string token;
    long long sum = 0;
    int numbers = 0;
    int words = 0;

    while (in >> token)
    {
        try
        {
            size_t idx = 0;
            long long value = stoll(token, &idx);
            if (idx == token.size())
            {
                sum += value;
                numbers++;
            }
            else
            {
                words++;
            }
        }
        catch (...)
        {
            words++;
        }
    }

    cout << "Words: " << words << ", Numbers: " << numbers << ", Sum(numbers) = " << sum << "\n";
    return 0;
}
