#include <iostream>
using namespace std;

// Function to perform Selection Sort
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;               // Assume the first unsorted element is the smallest
        for (int j = i + 1; j < n; j++) // Start comparison from the next element
        {
            if (arr[j] < arr[minIndex]) // Update minIndex if a smaller element is found
            {
                minIndex = j;
            }
        }
        // Swap the smallest element found with the first unsorted element
        swap(arr[minIndex], arr[i]);
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

    selectionSort(arr, n); 

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
