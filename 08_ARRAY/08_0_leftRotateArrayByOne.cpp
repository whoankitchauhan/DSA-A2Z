#include <iostream>
#include <vector>
using namespace std;

// Function to left rotate an array by one position
void leftRotateArrayByOne(vector<int> &arr)
{
    int n = arr.size();
    int temp = arr[0]; // Store the first element
    for (int i = 0; i < n - 1; i++)
    {
        arr[i] = arr[i + 1]; // Shift elements to the left
    }
    arr[n - 1] = temp; // Move the first element to the end
}

// Main function for testing
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    cout << "Original Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    leftRotateArrayByOne(arr);

    cout << "Array after Left Rotation by One: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
