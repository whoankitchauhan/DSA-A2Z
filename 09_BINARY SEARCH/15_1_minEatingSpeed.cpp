#include <bits/stdc++.h>
using namespace std;

bool canFinish(const vector<int> &piles, long long k, long long H)
{
    long long hours = 0;
    for (int p : piles)
    {
        // ceil(p / k) using integer arithmetic
        hours += (p + k - 1) / k;
        if (hours > H)
            return false; // early exit
    }
    return hours <= H;
}

int minEatingSpeed(vector<int> &piles, long long H)
{
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());

    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (canFinish(piles, mid, H))
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}

// Driver with example tests
int main()
{
    vector<pair<vector<int>, long long>> tests = {
        {{3, 6, 7, 11}, 8},       // expected 4
        {{30, 11, 23, 4, 20}, 5}, // expected 30
        {{30, 11, 23, 4, 20}, 6}, // expected 23
        {{1, 1, 1, 1}, 4},        // expected 1
        {{312884470}, 312884469}}; // large example: H slightly less than pile,

    for (int i = 0; i < tests.size(); ++i)
    {
        auto piles = tests[i].first;
        long long H = tests[i].second;
        cout << "Test " << i + 1 << " -> piles: [";
        for (int j = 0; j < piles.size(); ++j)
        {
            if (j)
                cout << ", ";
            cout << piles[j];
        }
        cout << "], H = " << H << "\n";

        int ans = minEatingSpeed(piles, H);
        cout << "  Minimum speed k = " << ans << "\n\n";
    }
    return 0;
}
