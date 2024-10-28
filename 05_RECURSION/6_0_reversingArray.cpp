#include <iostream>
#include <algorithm>
using namespace std;

// Recursive function to reverse the array
void reverseArray(int arr[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    swap(arr[left], arr[right]);            // Swap elements at 'left' and 'right'
    reverseArray(arr, left + 1, right - 1); // Recursive call
}

// Function to print the array (const to indicate no modification)
void printArray(const int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculates the array size dynamically

    cout << "Original Array: ";
    printArray(arr, n);

    // Reverse the array
    reverseArray(arr, 0, n - 1);

    // Print the reversed array
    cout << "After Reversing Array: ";
    printArray(arr, n);

    return 0;
}
