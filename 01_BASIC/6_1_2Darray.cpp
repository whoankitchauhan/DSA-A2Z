#include <iostream>
using namespace std;

int main()
{
    // Declaration and initialization of a 2D array with dimensions 2x3
    int arr[2][3] = {
        {1, 2, 3}, // First row: 1, 2, 3
        {4, 5, 6}  // Second row: 4, 5, 6
    };

    // Accessing and printing individual elements
    cout << "Value at arr[1][2]: " << arr[1][2] << endl;

    // Nested loops to iterate through all elements and print the entire array
    cout << "Printing the entire array:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl; // Move to the next row after printing a row
    }

    // Taking user input to modify an element
    int row, col, value;
    cout << "Enter row index (0 or 1): ";
    cin >> row;
    cout << "Enter column index (0, 1, or 2): ";
    cin >> col;
    cout << "Enter new value: ";
    cin >> value;

    // Assign the user-input value to the specified element
    arr[row][col] = value;

    // Printing the modified element and the entire array
    cout << "Value at arr[" << row << "][" << col << "]: " << arr[row][col] << endl;
    cout << "Printing the modified array:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
