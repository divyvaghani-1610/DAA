#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

int search(int *a, int n, int x)
{
    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            auto end = high_resolution_clock::now();
            auto duration = duration_cast<nanoseconds>(end - start);
            cout << "Element found at index: " << i << endl;
            cout << "Time taken: " << duration.count() << " nanoseconds" << endl;
            return i;
        }
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Element not found." << endl;
    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;

    return -1;
}

int main()
{
    int x = 999988889;
    int n = 1000000;

    // Dynamically allocate memory for the array
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = i;
    }

    int result = search(a, n, x);

    // Free the dynamically allocated memory
    delete[] a;

    return 0;
}