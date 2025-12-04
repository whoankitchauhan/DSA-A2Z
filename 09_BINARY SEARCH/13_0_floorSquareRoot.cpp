#include <bits/stdc++.h>
using namespace std;

int sqrtBinarySearch(int n)
{
    int low = 1, high = n, ans = 0;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2; // avoid overflow
        long long sq = mid * mid;

        if (sq == n)
        {
            return mid; // perfect square
        }
        else if (sq < n)
        {
            ans = mid; // possible floor
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans; // floor sqrt(n)
}

int main()
{
    vector<int> tests = {1, 4, 20, 36, 99, 100, 2147395599};

    for (int n : tests)
    {
        cout << "n = " << n
             << " -> Square Root = " << sqrtBinarySearch(n)
             << "\n";
    }
    return 0;
}
