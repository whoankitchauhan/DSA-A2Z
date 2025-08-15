#include <bits/stdc++.h>
using namespace std;

// Optimal Solution: O(N) Time | O(N) Space
int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> st(nums.begin(), nums.end());
    int longest = 0;

    for (int num : st)
    {
        // Check if it's the start of a sequence
        if (st.find(num - 1) == st.end())
        {
            int currentNum = num;
            int count = 1;

            // Count consecutive numbers
            while (st.find(currentNum + 1) != st.end())
            {
                currentNum++;
                count++;
            }
            longest = max(longest, count);
        }
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
