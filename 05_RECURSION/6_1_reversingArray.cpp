#include <iostream>
#include <algorithm>
using namespace std;

// Recursive function to reverse the array using one-pointer approach
void reverseArray(int arr[], int i, int n)
{
    if (i >= n / 2)
    { // Stop once the midpoint is reached
        return;
    }
    swap(arr[i], arr[n - i - 1]); // Swap elements at 'i' and 'n-i-1'
    reverseArray(arr, i + 1, n);  // Recursive call with incremented index
}

// Function to print the array
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
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate array size dynamically

    cout << "Original Array: ";
    printArray(arr, n);

    // Reverse the array
    reverseArray(arr, 0, n);

    // Print the reversed array
    cout << "After Reversing Array: ";
    printArray(arr, n);

    return 0;
}
