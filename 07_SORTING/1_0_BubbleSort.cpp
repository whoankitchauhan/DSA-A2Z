#include <iostream>
using namespace std;

// Bubble Sort Algorithm
void bubbleSort(int arr[], int n)
{
    // Traverse through all elements in the array
    for (int i = 0; i < n - 1; i++)
    {
        // Last i elements are already sorted
        for (int j = 0; j < n - 1 - i; j++)
        {
            // Swap if the element found is greater than the next element
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Function to print an array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, n); // Sorting the array
    cout << "Sorted array: ";
    printArray(arr, n); // Print the sorted array
    return 0;
}
