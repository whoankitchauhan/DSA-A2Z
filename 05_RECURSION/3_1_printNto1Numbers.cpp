#include <iostream>
using namespace std;

// Recursive function to fill the array in descending order from n down to 1
void fillDescending(int arr[], int current, int n)
{
    if (current < 1) // Base case: when current goes below 1, stop recursion
        return;

    arr[n - current] = current;          // Assign the current value to the correct position
    fillDescending(arr, current - 1, n); // Recursive call for the next number
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int arr[n]; // Create an array of size n

    fillDescending(arr, n, n); // Fill the array with numbers from n to 1

    // Print the array contents
    cout << "Generated array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
