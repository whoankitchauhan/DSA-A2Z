#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;
    int ans = nums.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> tests = {
        {1, 3, 5, 6}, // standard case
        {1, 3, 5, 6}, // target smaller than all
        {1, 3, 5, 6}, // target larger than all
        {1, 3, 5, 6}, // target somewhere in middle
        {2},          // single-element
        {}            // empty array
    };

    vector<int> targets = {
        5, // exists → index 2
        0, // insert at 0
        7, // insert at 4
        4, // insert at 2
        3, // insert at 1
        10 // empty array → index 0
    };

    for (int i = 0; i < tests.size(); ++i)
    {
        cout << "Test Case " << i + 1 << " -> ";
        int idx = searchInsert(tests[i], targets[i]);
        cout << "Target: " << targets[i] << ", Index: " << idx << "\n";
    }

    return 0;
}
