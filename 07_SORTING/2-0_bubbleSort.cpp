#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) // Outer loop for passes
    {
        bool swapped = false;               // Flag to check if a swap occurred
        for (int j = 0; j < n - i - 1; j++) // Inner loop for adjacent comparisons
        {
            if (arr[j] > arr[j + 1]) // Swap if needed
            {
                swap(arr[j], arr[j + 1]);
                swapped = true; // Mark that a swap occurred
            }
        }
        if (!swapped) // If no swaps, the array is sorted
            break;
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
