#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

int main()
{
    mutex m;
    int counter = 0;

    auto worker = [&](int times)
    {
        for (int i = 0; i < times; i++)
        {
            lock_guard<mutex> lock(m);
            counter++;
        }
    };

    thread t1(worker, 100000);
    thread t2(worker, 100000);

    t1.join();
    t2.join();

    cout << "counter = " << counter << "\n";
    return 0;
}
