#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono;
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int a[], int n)
{
    int min = 0, minIndex = 0, j = 0;
    for (int i = 0; i < n; i++)
    {

        min = a[i];
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);
    }
}

main()
{
    int n = 1000000;
    int *a = new int[n];

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
    {
        // for best  case
        a[i] = i;
        // for worst case
        // a[i] = n - i;
    }

    selectionSort(a, 67435);

    auto elapsed = high_resolution_clock::now() - start;
    long long time_taken = duration_cast<nanoseconds>(elapsed).count();

    cout << endl;
    cout << "Time taken by algoridhm is :" << time_taken << endl;
    return 0;
}