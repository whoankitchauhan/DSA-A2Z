#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> result;
    if (matrix.empty())
        return result;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right)
    {
        // 1. Left → Right
        for (int j = left; j <= right; j++)
        {
            result.push_back(matrix[top][j]);
        }
        top++;

        // 2. Top → Bottom
        for (int i = top; i <= bottom; i++)
        {
            result.push_back(matrix[i][right]);
        }
        right--;

        // 3. Right → Left (check if row still exists)
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                result.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        // 4. Bottom → Top (check if column still exists)
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return result;
}

void printVector(const vector<int> &vec)
{
    for (int val : vec)
        cout << val << " ";
    cout << endl;
}

// Driver Code
int main()
{
    // Test Case 1: 3x3 matrix
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    cout << "Spiral Order (Test Case 1): ";
    printVector(spiralOrder(matrix1)); // Expected: 1 2 3 6 9 8 7 4 5

    // Test Case 2: 3x4 matrix
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    cout << "Spiral Order (Test Case 2): ";
    printVector(spiralOrder(matrix2)); // Expected: 1 2 3 4 8 12 11 10 9 5 6 7

    // Test Case 3: Single row
    vector<vector<int>> matrix3 = {
        {1, 2, 3, 4, 5}};
    cout << "Spiral Order (Test Case 3): ";
    printVector(spiralOrder(matrix3)); // Expected: 1 2 3 4 5

    // Test Case 4: Single column
    vector<vector<int>> matrix4 = {
        {1},
        {2},
        {3},
        {4}};
    cout << "Spiral Order (Test Case 4): ";
    printVector(spiralOrder(matrix4)); // Expected: 1 2 3 4

    // Test Case 5: Empty matrix
    vector<vector<int>> matrix5 = {};
    cout << "Spiral Order (Test Case 5): ";
    printVector(spiralOrder(matrix5)); // Expected: (empty)

    return 0;
}
