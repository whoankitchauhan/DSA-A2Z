#include <bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int> &arr, int target)
{
    int n = arr.size();
    int first = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

    if (first == n || arr[first] != target)
        return {-1, -1};

    int last = upper_bound(arr.begin(), arr.end(), target) - arr.begin() - 1;
    return {first, last};
}

int main()
{
    vector<vector<int>> tests = {
        {5, 7, 7, 8, 8, 10},
        {1, 2, 3, 4, 5},
        {2, 2, 2, 2, 2},
        {1},
        {}};

    vector<int> targets = {8, 6, 2, 1, 3};

    for (int i = 0; i < tests.size(); ++i)
    {
        auto ans = searchRange(tests[i], targets[i]);
        cout << "Test " << i + 1
             << " -> Target: " << targets[i]
             << " | First: " << ans[0]
             << " | Last: " << ans[1] << "\n";
    }

    return 0;
}
