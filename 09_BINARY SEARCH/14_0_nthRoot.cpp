#include <bits/stdc++.h>
using namespace std;

int checkPower(long long mid, int n, long long m)
{
    long long answer = 1;

    for (int i = 0; i < n; ++i)
    {
        answer *= mid;
        if (answer > m)
            return 1; // too large
    }

    if (answer == m)
        return 0; // exact match
    return -1;    // too small
}

int nthRoot(int n, long long m)
{
    if (m == 0)
        return 0; // FIX: nth root of 0 is 0

    long long low = 1;
    long long high = m;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        int res = checkPower(mid, n, m);

        if (res == 0)
            return mid;
        else if (res == -1)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // no exact integer root
}

int main()
{
    cout << "3rd root of 27: " << nthRoot(3, 27) << "\n";
    cout << "4th root of 16: " << nthRoot(4, 16) << "\n";
    cout << "3rd root of 28: " << nthRoot(3, 28) << "\n";
    cout << "2nd root of 49: " << nthRoot(2, 49) << "\n";
    cout << "6th root of 64: " << nthRoot(6, 64) << "\n";
    return 0;
}
