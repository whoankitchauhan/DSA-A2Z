#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--) // Outer loop to iterate over passes
    {
        for (int j = 0; j < i; j++) // Inner loop for adjacent comparisons
        {
            if (arr[j] > arr[j + 1]) // Swap if elements are in the wrong order
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to print the array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {90, 10, 50, 60, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    printArray(arr, n);

    bubbleSort(arr, n); // Sort the array

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
