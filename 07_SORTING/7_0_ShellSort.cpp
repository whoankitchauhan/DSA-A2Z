#include <iostream>
using namespace std;

// Shell Sort Algorithm
void shellSort(int arr[], int n)
{
    // Start with a large gap and reduce the gap
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Perform a gapped insertion sort for this gap size
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            // Shift elements of arr[0..i-gap] to make space for arr[i]
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

// Function to print the array
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

    shellSort(arr, n); // Sorting the array
    cout << "Sorted array: ";
    printArray(arr, n); // Print the sorted array
    return 0;
}
