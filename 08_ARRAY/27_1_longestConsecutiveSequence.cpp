#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    sort(nums.begin(), nums.end());

    int longest = 1, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
            continue; // skip duplicates

        if (nums[i] == nums[i - 1] + 1)
        {
            count++;
        }
        else
        {
            count = 1;
        }
        longest = max(longest, count);
    }
    return longest;
}

// Driver code
int main()
{
    vector<vector<int>> testCases = {
        {100, 4, 200, 1, 3, 2},
        {0, 3, 7, 2, 5, 8, 4, 6, 0, 1},
        {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6},
        {},
        {1},
        {10, 20, 30, 40},
        {1, 2, 0, 1}};

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test case " << i + 1 << ": ";
        cout << longestConsecutive(testCases[i]) << endl;
    }

    return 0;
}
