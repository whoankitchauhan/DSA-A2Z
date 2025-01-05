#include <iostream>
#include <vector>
using namespace std;

// Function to left rotate an array by 'k' positions
vector<int> leftRotateArrayBykSteps(vector<int> arr, int k)
{
    int n = arr.size();

    // No rotation needed if the array is empty or if k is a multiple of the array size
    if (n == 0 || k % n == 0)
        return arr;

    // Adjust k to be within the range [0, n)
    k %= n;

    // Temporary array to store the first 'k' elements
    vector<int> temp(k);
    for (int i = 0; i < k; i++)
    {
        temp[i] = arr[i];
    }

    // Shift the remaining elements to the left by 'k' positions
    for (int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }

    // Copy the elements from temp to the end of the array
    for (int i = 0; i < k; i++)
    {
        arr[n - k + i] = temp[i];
    }

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
