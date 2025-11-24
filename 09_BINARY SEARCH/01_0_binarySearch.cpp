#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    vector<vector<int>> tests = {
        {1, 3, 5, 7, 9, 11},    // normal sorted
        {-10, -3, 0, 5, 9, 12}, // includes negatives
        {2, 4, 4, 4, 6, 8},     // duplicates
        {5},                    // single element
        {}                      // empty case
    };

    vector<int> targets = {
        7,  // exists
        -3, // exists negative
        4,  // duplicate case
        5,  // single element match
        10  // doesn't exist
    };

    for (int i = 0; i < tests.size(); ++i)
    {
        cout << "Test Case " << i + 1 << " -> ";
        int idx = binarySearch(tests[i], targets[i]);
        cout << "Target: " << targets[i] << ", Index: " << idx << "\n";
    }

    return 0;
}
