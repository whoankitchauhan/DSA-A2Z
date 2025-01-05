#include <iostream>
#include <vector>
#include <algorithm> // For std::reverse

using namespace std;

// Function to left rotate an array by 'k' positions
vector<int> leftRotateArrayBykSteps(vector<int> &arr, int k)
{
    int n = arr.size();

    // Handle edge cases
    if (n == 0 || k % n == 0) // No rotation needed if array is empty or k is a multiple of n
        return arr;

    k %= n; // Adjust k to be within the bounds of the array

    // Step 1: Reverse the first 'k' elements
    reverse(arr.begin(), arr.begin() + k);

    // Step 2: Reverse the remaining elements
    reverse(arr.begin() + k, arr.end());

    // Step 3: Reverse the entire array
    reverse(arr.begin(), arr.end());

    return arr;
}

// Main function for testing
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 2;

    cout << "Original Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> rotatedArray = leftRotateArrayBykSteps(arr, k);

    cout << "Array after Left Rotation by " << k << " positions: ";
    for (int num : rotatedArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
