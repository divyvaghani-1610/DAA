#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono;
using namespace std;

int lcs(string X, string Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return max(lcs(X, Y, m, n - 1),
                   lcs(X, Y, m - 1, n));
}

int main()
{
    string S1 = "ILOVEDAA";
    string S2 = "ILOVECODE";
    int m = S1.size();
    int n = S2.size();

    auto start = high_resolution_clock::now();

    cout << "Length of LCS is " << lcs(S1, S2, m, n) << " ";

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Element not found." << endl;
    cout << "Time taken: " << duration.count() << " nanoseconds" << endl;

    return 0;
}