#include <bits/stdc++.h>
using namespace std;

void rotateMatrix90Clockwise(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotated[j][n - 1 - i] = matrix[i][j];
        }
    }
    matrix = rotated;
}

void printMatrix(const vector<vector<int>> &mat)
{
    for (auto &row : mat)
    {
        for (auto &x : row)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    rotateMatrix90Clockwise(matrix);

    cout << "\nMatrix After 90-degree Clockwise Rotation:\n";
    printMatrix(matrix);

    return 0;
}
