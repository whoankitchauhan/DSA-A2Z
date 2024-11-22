#include <iostream>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(int arr[], int n)
{
    // Start from the second element (index 1) because the first element is already "sorted"
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];       // Store the current element (key) to be placed in the sorted part
        int j = i - 1;          // Index of the last element in the sorted part

        // Shift all elements greater than 'key' one position to the right
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // Move element to the right
            j--;                 // Move backward in the sorted part
        }

        // Place the 'key' at its correct position
        arr[j + 1] = key;
    }
}

// Function to print the elements of the array
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

    insertionSort(arr, n); 

    cout << "Sorted Array: ";
    printArray(arr, n); 

    return 0; 
}
