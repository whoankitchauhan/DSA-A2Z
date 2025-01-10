#include <iostream>
#include <vector>
#include <climits> // For INT_MIN
using namespace std;

// Function to find the maximum subarray sum and the subarray itself
pair<int, vector<int>> maxSubArrayWithSubarray(vector<int> &nums)
{
    int currentSum = 0;                    // Current subarray sum
    int maxSubarraySum = INT_MIN;          // Maximum subarray sum
    int start = 0, end = 0, tempStart = 0; // Indices to track the subarray

    for (int i = 0; i < nums.size(); i++)
    {
        currentSum += nums[i];

        // Update maximum sum and indices
        if (currentSum > maxSubarraySum)
        {
            maxSubarraySum = currentSum;
            start = tempStart; // Update start of the max subarray
            end = i;           // Update end of the max subarray
        }

        // Reset currentSum if it becomes negative
        if (currentSum < 0)
        {
            currentSum = 0;
            tempStart = i + 1; // Update tempStart for the next potential subarray
        }
    }

    // Extract the subarray using start and end indices
    vector<int> subarray(nums.begin() + start, nums.begin() + end + 1);

    return {maxSubarraySum, subarray};
}

// Main function to test the algorithm
int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    auto result = maxSubArrayWithSubarray(nums);

    cout << "Maximum Subarray Sum: " << result.first << endl;
    cout << "Subarray: ";
    for (int num : result.second)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
