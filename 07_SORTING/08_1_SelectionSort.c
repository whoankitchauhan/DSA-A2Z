#include <stdio.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        // Assume the minimum element is the first unsorted element
        int minIndex = i;

        // Find the index of the minimum element in the unsorted portion
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first unsorted element
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {29, 10, 14, 37, 14};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    selectionSort(arr, size);

    printf("Sorted array using Selection Sort:\n");
    printArray(arr, size);

    return 0;
}
