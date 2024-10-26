#include <iostream>
using namespace std;

// Recursive function to fill the array in ascending order from 1 to n
void fillAscending(int arr[], int current, int n)
{
    if (current > n) // Base case: when current exceeds n, stop recursion
        return;

    arr[current - 1] = current;         // Assign the current value to the correct position
    fillAscending(arr, current + 1, n); // Recursive call for the next number
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int arr[n]; // Create an array of size n

    fillAscending(arr, 1, n); // Fill the array with numbers from 1 to n

    // Print the array contents
    cout << "Generated array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
