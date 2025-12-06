#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int> &piles, long long H)
{
    int maxPile = *max_element(piles.begin(), piles.end());

    for (int k = 1; k <= maxPile; ++k)
    {
        long long hours = 0;

        for (int p : piles)
        {
            hours += (p + k - 1) / k; // ceil(p/k)
        }

        if (hours <= H)
            return k;
    }
    return maxPile; // fallback, but this line never actually needed
}

// Driver with example tests
int main()
{
    vector<pair<vector<int>, long long>> tests = {
        {{3, 6, 7, 11}, 8},        // expected 4
        {{30, 11, 23, 4, 20}, 5},  // expected 30
        {{30, 11, 23, 4, 20}, 6},  // expected 23
        {{1, 1, 1, 1}, 4},         // expected 1
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
