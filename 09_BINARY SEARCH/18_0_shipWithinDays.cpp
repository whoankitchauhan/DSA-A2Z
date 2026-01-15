#include <bits/stdc++.h>
using namespace std;

bool canShip(vector<int> &weights, int days, int capacity)
{
    int currLoad = 0;
    int usedDays = 1;

    for (int w : weights)
    {
        if (currLoad + w > capacity)
        {
            usedDays++;
            currLoad = 0;
        }
        currLoad += w;

        if (usedDays > days)
            return false;
    }
    return true;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int low = *max_element(weights.begin(), weights.end());
    long long high = 0;
    for (int w : weights)
        high += w;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (canShip(weights, days, mid))
            high = mid - 1; // try smaller capacity
        else
            low = mid + 1; // need larger capacity
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
    vector<vector<int>> tests = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, // standard
        {3, 2, 2, 4, 1, 4},              // classic example
        {1, 2, 3, 1, 1},                 // small loads
        {10, 50, 100, 100, 50, 100},     // varying weights
        {5, 5, 5, 5, 5},                 // uniform
        {1000000000}                     // single heavy package
    };

    vector<int> days = {
        5, // expected 15
        3, // expected 6
        4, // expected 3
        3, // expected 150
        5, // expected 5
        1  // expected 1000000000
    };

    for (int i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << i + 1 << "\n";
        cout << "Weights = ";
        printVector(tests[i]);
        cout << "\nDays = " << days[i] << "\n";

        int ans = shipWithinDays(tests[i], days[i]);
        cout << "Minimum Capacity = " << ans << "\n\n";
    }

    return 0;
}
