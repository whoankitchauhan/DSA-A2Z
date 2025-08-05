#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Kadane's Algorithm Optimal
int maxSubArray(vector<int> &nums)
{
    int maxSum = nums[0], curSum = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
        curSum = max(nums[i], curSum + nums[i]);
        maxSum = max(maxSum, curSum);
    }
    return maxSum;
}

int main()
{
    vector<vector<int>> testCases = {
        {-2, 1, -3, 4, -1, 2, 1, -5, 4},
        {1},
        {5, 4, -1, 7, 8},
        {-1, -2, -3, -4},
        {-2, 1}};

    for (int i = 0; i < testCases.size(); ++i)
    {
        cout << "Test Case " << i + 1 << ": ";
        for (int num : testCases[i])
            cout << num << " ";
        cout << "\n";

        vector<int> nums = testCases[i];

        cout << maxSubArray(nums) << "\n";
        cout << "-------------------------\n";
    }

    return 0;
}
