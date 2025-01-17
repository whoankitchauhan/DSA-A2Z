#include <iostream>
#include <vector>
using namespace std;

// Function to find the k-th missing positive number
int findKthPositive(vector<int> &arr, int k)
{
    int low = 0;               // Initialize the starting index
    int high = arr.size() - 1; // Initialize the ending index

    // Binary search to find the position of k-th missing number
    while (low <= high)
    {
        int mid = (low + high) / 2;         // Calculate the middle index
        int missing = arr[mid] - (mid + 1); // Calculate the number of missing elements up to index 'mid'

        if (missing < k)
        {
            // If the number of missing elements so far is less than k,
            // move to the right half to search for the k-th missing number
            low = mid + 1;
        }
        else
        {
            // Otherwise, move to the left half
            high = mid - 1;
        }
    }

    // At the end of the loop, 'low' points to the position where the k-th missing number lies
    return low + k;
}

int main()
{
    // Test case 1
    vector<int> arr1 = {2, 3, 4, 7, 11}; // Input array
    int k1 = 5;                          // Find the 5th missing positive number
    cout << "The 5th missing positive is: " << findKthPositive(arr1, k1) << endl;

    // Test case 2
    vector<int> arr2 = {1, 2, 3, 4}; // Input array
    int k2 = 2;                      // Find the 2nd missing positive number
    cout << "The 2nd missing positive is: " << findKthPositive(arr2, k2) << endl;

    // Test case 3
    vector<int> arr3 = {3, 10, 20}; // Input array
    int k3 = 10;                    // Find the 10th missing positive number
    cout << "The 10th missing positive is: " << findKthPositive(arr3, k3) << endl;

    return 0; // Indicate successful execution
}
