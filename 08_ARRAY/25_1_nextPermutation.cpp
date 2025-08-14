#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    if (nums.size() <= 1)
        return;

    int i = nums.size() - 2;

    // Step 1: Find the first index 'i' where nums[i] < nums[i + 1]
    while (i >= 0 && nums[i] >= nums[i + 1])
        i--;

    // Step 2: If such index is found, find 'j' to swap with
    if (i >= 0)
    {
        int j = nums.size() - 1;
        while (nums[j] <= nums[i])
            j--;
        swap(nums[i], nums[j]);
    }

    // Step 3: Reverse the suffix starting from i+1 to end
    reverse(nums.begin() + i + 1, nums.end());
}

int main()
{
    vector<vector<int>> tests = {
        {1, 2, 3},
        {3, 2, 1},
        {1, 1, 5},
        {1, 3, 2},
        {1},
        {1, 5, 1}};

    for (auto nums : tests)
    {
        cout << "Input: ";
        for (int x : nums)
            cout << x << " ";
        cout << "\n";

        nextPermutation(nums);

        cout << "Next Permutation: ";
        for (int x : nums)
            cout << x << " ";
        cout << "\n\n";
    }

    return 0;
}
