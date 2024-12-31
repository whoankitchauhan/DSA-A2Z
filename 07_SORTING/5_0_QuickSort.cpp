#include <iostream>
using namespace std;

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot element
    int i = (low - 1);

    // Rearranging elements based on pivot
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot at the correct position
    return (i + 1);
}

// Quick Sort Algorithm
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition index

        // Recursively sort the two halves
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1); // Sorting the array
    cout << "Sorted array: ";
    printArray(arr, n); // Print the sorted array
    return 0;
}
