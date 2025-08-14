#include <bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int breakPoint = -1;

    // Step 1: Find the first decreasing element from the end
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            breakPoint = i;
            break;
        }
    }

    // Step 2: If no such element is found, reverse entire array
    if (breakPoint == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    // Step 3: Find the smallest element greater than nums[breakPoint] from the end
    for (int j = nums.size() - 1; j > breakPoint; j--)
    {
        if (nums[j] > nums[breakPoint])
        {
            swap(nums[j], nums[breakPoint]);
            break;
        }
    }

    // Step 4: Reverse the subarray after the breakPoint
    reverse(nums.begin() + breakPoint + 1, nums.end());
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
