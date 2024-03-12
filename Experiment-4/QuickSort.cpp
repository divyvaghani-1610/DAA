#include <iostream>
#include <string>
#include <chrono>
using namespace std;
using namespace std::chrono;

int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (!(a[i] > pivot));
        do
        {
            j--;
        } while (!(a[j] <= pivot));
        if (i < j)
        {
            swap(a[i], a[j]);
        }
    } while (i < j);

    swap(a[l], a[j]);

    return j;
}

void QuickSort(int a[], int l, int h)
{
    if (l < h)
    {
        int j = partition(a, l, h);
        QuickSort(a, l, j);
        QuickSort(a, j + 1, h);
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
main()
{
    int n = 1000;
    int *a = new int[n];

    for (int i = 0; i < n; i++)
    {
        a[i] = i; // for sorted data
                  // a[i] = n - i ;      // for unsorted data
    }

    auto start = high_resolution_clock::now();

    QuickSort(a, 0, n - 1);

    auto elapsed = high_resolution_clock::now() - start;
    long long time_taken = duration_cast<nanoseconds>(elapsed).count();

    cout << endl;
    cout << "Time taken by algoridhm is :" << time_taken << endl;
    return 0;
}