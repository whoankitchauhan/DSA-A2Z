#include <bits/stdc++.h>
using namespace std;

// Helper function to find the first occurrence (lower bound) of `1` in a sorted row
int findFirstOne(vector<int> &row, int cols)
{
    int low = 0;
    int high = cols - 1;
    int firstOneIndex = cols; // Default to cols if no `1` is found

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (row[mid] == 1)
        {
            firstOneIndex = mid; // Update the position of the first `1`
            high = mid - 1;      // Continue searching in the left half
        }
        else
        {
            low = mid + 1; // Search in the right half
        }
    }

    return firstOneIndex; // Return the index of the first `1`
}

// Function to find the index of the row with the maximum number of `1`s
int rowWithMaxOnes(vector<vector<int>> &matrix)
{
    int maxOnes = 0;   // Track the maximum count of `1`s
    int rowIndex = -1; // Track the index of the row with the maximum `1`s

    int rows = matrix.size();
    if (rows == 0)
        return -1; // If the matrix is empty, return -1

    int cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        // Find the count of `1`s in the current row
        int countOnes = cols - findFirstOne(matrix[i], cols);

        // Update the row index if the current row has more `1`s
        if (countOnes > maxOnes)
        {
            maxOnes = countOnes;
            rowIndex = i;
        }
    }

    return rowIndex; // Return the index of the row with the maximum `1`s
}

int main()
{
    // Predefined matrix
    vector<vector<int>> matrix = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1}};

    // Find and print the row with the maximum number of `1`s
    cout << "Row with the maximum number of 1s: " << rowWithMaxOnes(matrix) << endl;

    return 0;
}
