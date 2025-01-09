#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

int lenOfLongestSubarr_optimizedBruteForce(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxLength = 0;

    // Try every possible subarray
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j]; // Incrementally add to the sum
            // If the sum is equal to k, update maxLength
            if (sum == k)
            {
                maxLength = max(maxLength, j - i + 1);
            }
        }
    }

    return maxLength;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, -1, 2, 3}; // Example array
    int k = 6;                                   // Example target sum

    cout << "Length of longest subarray with sum " << k << " is: "
         << lenOfLongestSubarr_optimizedBruteForce(arr, k) << endl;

    return 0;
}
