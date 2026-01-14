#include <bits/stdc++.h>
using namespace std;

bool canMake(vector<int> &bloomDay, int day, int m, int k)
{
    int flowers = 0, bouquets = 0;

    for (int d : bloomDay)
    {
        if (d <= day)
        {
            flowers++;
            if (flowers == k)
            {
                bouquets++;
                flowers = 0;
            }
        }
        else
        {
            flowers = 0;
        }
    }
    return bouquets >= m;
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    if (1LL * m * k > bloomDay.size())
        return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canMake(bloomDay, mid, m, k))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
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
    vector<vector<int>> testBloom = {
        {1, 10, 3, 10, 2},        // basic
        {1, 10, 3, 10, 2},        // impossible
        {7, 7, 7, 7, 12, 7, 7},   // adjacency matters
        {1000000000, 1000000000}, // large values
        {1, 1, 1, 1},             // all same day
        {5, 5, 5, 5, 5, 5}        // exact fit
    };

    vector<pair<int, int>> mk = {
        {3, 1}, // expected 3
        {3, 2}, // expected -1
        {2, 3}, // expected 12
        {1, 1}, // expected 1000000000
        {2, 2}, // expected 1
        {2, 3}  // expected 5
    };

    for (int i = 0; i < testBloom.size(); ++i)
    {
        cout << "Test " << i + 1 << "\n";
        cout << "BloomDay: ";
        printVector(testBloom[i]);
        cout << "\nm = " << mk[i].first
             << ", k = " << mk[i].second << "\n";

        int ans = minDays(testBloom[i], mk[i].first, mk[i].second);
        cout << "Minimum Days = " << ans << "\n\n";
    }

    return 0;
}
