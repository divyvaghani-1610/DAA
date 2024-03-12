#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
int main()
{
    int s;
    auto start = high_resolution_clock::now();
    // function start
    for (int i = 0; i < 1000000000; i++)
    {
        s += i;
    }
    // function end

    auto elapsed = high_resolution_clock::now() - start;
    long long nanosecands = duration_cast<nanoseconds>(elapsed).count();
    cout << nanosecands;
}