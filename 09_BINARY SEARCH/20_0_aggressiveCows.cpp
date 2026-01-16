#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int> &stalls, int cows, int dist)
{
    int count = 1;
    int lastPos = stalls[0];

    for (int i = 1; i < stalls.size(); ++i)
    {
        if (stalls[i] - lastPos >= dist)
        {
            count++;
            lastPos = stalls[i];
        }
        if (count == cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int cows)
{
    sort(stalls.begin(), stalls.end());

    int maxDist = stalls.back() - stalls.front();
    int ans = 0;

    for (int d = 1; d <= maxDist; ++d)
    {
        if (canPlace(stalls, cows, d))
        {
            ans = d;
        }
    }
    return ans;
}

void printVector(const vector<int> &v)
{
    cout << "[";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i];
        if (i + 1 < v.size())
            cout << ", ";
    }
    cout << "]";
}

int main()
{
    vector<vector<int>> tests = {
        {1, 2, 4, 8, 9},  // classic
        {10, 1, 2, 7, 5}, // unsorted
        {1, 3, 5, 7, 9},  // evenly spaced
        {1, 2},           // minimal case
        {1, 1000000000}   // extreme gap
    };

    vector<int> cows = {
        3, // expected 3
        3, // expected 4
        3, // expected 4
        2, // expected 1
        2  // expected 999999999
    };

    vector<int> expected = {
        3, 4, 4, 1, 999999999};

    for (int i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << i + 1 << "\n";
        cout << "Stalls = ";
        printVector(tests[i]);
        cout << "\nCows = " << cows[i] << "\n";

        int ans = aggressiveCows(tests[i], cows[i]);

        cout << "Expected = " << expected[i] << "\n";
        cout << "Actual   = " << ans << "\n\n";
    }

    return 0;
}
