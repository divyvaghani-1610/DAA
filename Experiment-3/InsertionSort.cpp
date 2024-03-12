#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono;
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int N = 10;
    int arr[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = i; // for best  case
        // arr[i] = N - i; // for worst case
    }

    auto start = high_resolution_clock::now();

    insertionSort(arr, N);
    printArray(arr, N);

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Element not found." << endl;
    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;

    return 0;
}