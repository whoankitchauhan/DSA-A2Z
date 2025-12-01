

#include <bits/stdc++.h>
using namespace std;

int searchInRotatedSortedArray(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); ++i)
        if (nums[i] == target)
            return i;
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
