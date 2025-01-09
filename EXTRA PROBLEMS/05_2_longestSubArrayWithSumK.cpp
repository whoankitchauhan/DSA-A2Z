#include <iostream>
#include <vector>
#include <unordered_map> 

using namespace std;

int lenOfLongestSubarr_optimal(vector<int>& arr, int k) {
    unordered_map<int, int> preSumMap;  // This map stores the first occurrence of each prefix sum
    int maxLength = 0;
    int sum = 0;

    // Initialize the map with the base case: prefix sum of 0 at index -1
    preSumMap[0] = -1;  // This helps handle the case where the subarray starts at index 0

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];  // Increment the running sum
        
        // Check if the current sum itself equals k (subarray from index 0 to i)
        if (sum == k) {
            maxLength = max(maxLength, i + 1);  // Subarray from index 0 to i
        }

        // Calculate the remaining sum we need to find in the map
        int prefixSumToFind = sum - k;

        // Check if the remaining sum (sum - k) has appeared before
        if (preSumMap.find(prefixSumToFind) != preSumMap.end()) {
            // If it exists, we found a subarray with sum = k
            int length = i - preSumMap[prefixSumToFind];
            maxLength = max(maxLength, length);
        }

        // Store the first occurrence of the current sum if it's not already in the map
        if (preSumMap.find(sum) == preSumMap.end()) {
            preSumMap[sum] = i;  // Store the first occurrence of this prefix sum
        }
    }

    return maxLength;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, -1, 2, 3};  // Example array
    int k = 6;  // Target sum

    cout << "Length of longest subarray with sum " << k << " is: " 
         << lenOfLongestSubarr_optimal(arr, k) << endl;

    return 0;
}
