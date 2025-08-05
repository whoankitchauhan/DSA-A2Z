#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Brute-force
int maxSubArray(vector<int> &nums)
{
    int n = nums.size();
    int maxSum = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            int sum = 0;
            for (int k = i; k <= j; ++k)
            {
                sum += nums[k];
            }
            maxSum = max(maxSum, sum);
        }
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
