#include <iostream>
#include <chrono>
#include <climits>

using namespace std;
using namespace std::chrono;

int binarySearch(int arr[], int n, int x)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter The Number : ";
    cin >> n;

    auto start = high_resolution_clock::now();
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
        arr[i] = i;

    int result = binarySearch(arr, n, 12);
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<nanoseconds>(stop - start);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found." << endl;

    cout << "Time taken by algorithm: " << duration.count() << " nanoseconds" << endl;

    delete[] arr;
    return 0;
}