#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    int longest = 1;
    for (int i = 0; i < n; i++)
    {
        int currentNum = nums[i];
        int count = 1;

        // Keep checking next consecutive numbers
        while (find(nums.begin(), nums.end(), currentNum + 1) != nums.end())
        {
            currentNum += 1;
            count++;
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
