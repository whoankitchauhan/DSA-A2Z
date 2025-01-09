#include <iostream>
#include <vector>
#include <unordered_map> // For unordered_map

using namespace std;

int lenOfLongestSubarr_optimal(vector<int> &arr, int k)
{
    unordered_map<int, int> prefixSumMap; // Map to store prefix sums and their indices
    int sum = 0;
    int maxLength = 0;

    // Initialize the map with the base case: prefix sum of 0 at index -1
    prefixSumMap[0] = -1;

    // Traverse the array
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i]; // Increment the running sum

        // Check if there is a prefix sum such that sum - k exists in the map
        if (prefixSumMap.find(sum - k) != prefixSumMap.end())
        {
            // If we find such a prefix sum, calculate the length of the subarray
            int prevIndex = prefixSumMap[sum - k];
            maxLength = max(maxLength, i - prevIndex);
        }

        // Store the first occurrence of the current sum in the map
        if (prefixSumMap.find(sum) == prefixSumMap.end())
        {
            prefixSumMap[sum] = i;
        }
    }

    return maxLength;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, -1, 2, 3}; // Example array
    int k = 6;                                   // Example target sum

    cout << "Length of longest subarray with sum " << k << " is: "
         << lenOfLongestSubarr_optimal(arr, k) << endl;

    return 0;
}
