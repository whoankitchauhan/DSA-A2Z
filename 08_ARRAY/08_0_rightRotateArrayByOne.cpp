#include <iostream>
#include <vector>
using namespace std;

// Function to rotate the array by one position to the right
void rotateArrayByOne(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 1)
        return; // No rotation needed for empty or single-element arrays

    int temp = arr[n - 1]; // Store the last element

    // Shift elements to the right
    for (int i = n - 1; i >= 1; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[0] = temp; // Place the last element at the first position
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Original Array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    rotateArrayByOne(arr);

    cout << "Array after rotation: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
