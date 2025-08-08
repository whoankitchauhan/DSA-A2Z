#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Extended Kadane's Algorithm to also print subarray
void maxSubArray(vector<int> &nums)
{
    int maxSum = nums[0], curSum = nums[0];
    int start = 0, end = 0, tempStart = 0;

    for (int i = 1; i < nums.size(); ++i)
    {
        if (nums[i] > curSum + nums[i])
        {
            curSum = nums[i];
            tempStart = i; // start new subarray
        }
        else
        {
            curSum += nums[i];
        }

        if (curSum > maxSum)
        {
            maxSum = curSum;
            start = tempStart;
            end = i;
        }
    }

    cout << "Maximum Sum: " << maxSum << "\n";
    cout << "Subarray: ";
    for (int i = start; i <= end; ++i)
        cout << nums[i] << " ";
    cout << "\n";
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
        maxSubArray(nums);
        cout << "-------------------------\n";
    }

    return 0;
}
