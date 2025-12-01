#include <bits/stdc++.h>
using namespace std;

bool searchInRotatedSortedArrayII(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return true;

        // If duplicates block decision
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low++;
            high--;
        }
        // Left half sorted
        else if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half sorted
        else
        {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> tests = {
        {2, 5, 6, 0, 0, 1, 2},
        {2, 5, 6, 0, 0, 1, 2},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {},
    };

    vector<int> targets = {0, 3, 0, 2, 1};

    for (int i = 0; i < tests.size(); ++i)
    {
        auto &arr = tests[i];
        int t = targets[i];

        cout << "Test " << i + 1 << " -> Array: [";
        for (auto &num : arr)
        {

            cout << num << " ";
        }
        cout << "]\n";

        cout << "Target: " << targets[i]
             << " | Found: " << (searchInRotatedSortedArrayII(tests[i], targets[i]) ? "true" : "false")
             << "\n \n";
    }

    return 0;
}
