#include <bits/stdc++.h>
using namespace std;

int searchInRotatedSortedArray(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        // Left half is sorted
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // Right half is sorted
        else
        {
            if (nums[mid] < target && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    vector<vector<int>> tests = {
        {4, 5, 6, 7, 0, 1, 2},
        {4, 5, 6, 7, 0, 1, 2},
        {1, 2, 3, 4, 5, 6, 7},
        {1},
        {}};

    vector<int> targets = {0, 5, 3, 1, 10};

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

        // Print the target and the result
        cout << "Target: " << t
             << " | Answer: " << searchInRotatedSortedArray(arr, t) << "\n\n";
    }

    return 0;
}
