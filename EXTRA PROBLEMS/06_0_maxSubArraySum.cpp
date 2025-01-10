// Kadane's Algorithm
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the maximum sum of a contiguous subarray
int maxSubArray(vector<int> &numbers)
{
    int currentSum = 0;           // Current subarray sum
    int maxSubarraySum = INT_MIN; // To store the maximum subarray sum

    for (int i = 0; i < numbers.size(); i++)
    {
        currentSum += numbers[i]; // Add the current element to the running sum

        if (currentSum > maxSubarraySum)
        {
            maxSubarraySum = currentSum; // Update maxSubarraySum if the current sum is larger
        }

        if (currentSum < 0)
        {
            currentSum = 0; // Reset currentSum if it becomes negative
        }
    }

    return maxSubarraySum; // Return the maximum sum found
}

// Main function to test the algorithm
int main()
{
    vector<int> numbers = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxSubArray(numbers) << endl;

    return 0;
}
