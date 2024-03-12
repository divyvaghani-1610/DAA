#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono;
using namespace std;

int fact(int n);

main()
{
    cout << "Enter number : ";
    int n;
    cin >> n;

    auto start = high_resolution_clock::now();
    fact(n);
    auto elapsed = high_resolution_clock::now() - start;
    long long time_taken = duration_cast<nanoseconds>(elapsed).count();
    cout << endl
         << "Time taken by algoridhm is :" << time_taken << endl;
    return 0;
}

int fact(int n)
{
    if (n == 1 || n == 0)
        return 1;

    return n * fact(n - 1);
}