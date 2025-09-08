#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest subarray with sum = 0
int longestZeroSumSubarray(vector<int> &arr)
{
    unordered_map<int, int> prefixSumIndex; // Stores prefixSum -> first index
    int prefixSum = 0;
    int maxLength = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        prefixSum += arr[i];

        if (prefixSum == 0)
        {
            maxLength = i + 1; // Subarray from 0 to i
        }

        if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end())
        {
            maxLength = max(maxLength, i - prefixSumIndex[prefixSum]);
        }
        else
        {
            prefixSumIndex[prefixSum] = i; // Store only the first occurrence
        }
    }

    return maxLength;
}

// Helper function to print the result for a test case
void runTestCase(int testCaseNumber, const vector<int> &arr)
{
    cout << "Test Case " << testCaseNumber << ": ";
    for (int num : arr)
        cout << num << " ";
    cout << "\nLongest Zero Sum Subarray Length: " << longestZeroSumSubarray(const_cast<vector<int> &>(arr)) << "\n\n";
}

// Driver code
int main()
{
    vector<int> arr1 = {15, -2, 2, -8, 1, 7, 10, 23};
    vector<int> arr2 = {2, 10, 4};
    vector<int> arr3 = {1, -1, 3, 2, -2, -3, 3};

    runTestCase(1, arr1); // Expected Output: 5
    runTestCase(2, arr2); // Expected Output: 0
    runTestCase(3, arr3); // Expected Output: 6

    return 0;
}
