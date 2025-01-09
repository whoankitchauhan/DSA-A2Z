#include <iostream>
#include <vector>
#include <algorithm> // For std::max

using namespace std;

int lenOfLongestSubarr_bruteForce(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxLength = 0;

    // Try every possible subarray
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            // Calculate the sum of the subarray arr[i..j]
            for (int l = i; l <= j; l++)
            {
                sum += arr[l];
            }
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
         << lenOfLongestSubarr_bruteForce(arr, k) << endl;

    return 0;
}
