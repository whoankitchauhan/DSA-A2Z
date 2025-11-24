#include <bits/stdc++.h>
using namespace std;

int firstPos(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            high = mid - 1; // go LEFT
        }
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

int lastPos(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1; // go RIGHT
        }
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
}

vector<int> searchRange(vector<int> &arr, int target)
{
    return {firstPos(arr, target), lastPos(arr, target)};
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
