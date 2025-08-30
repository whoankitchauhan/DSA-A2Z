#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateMatrix90Clockwise(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    // Transpose
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // Reverse each row
    for (int i = 0; i < n; ++i)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

static void printMatrix(const vector<vector<int>> &a)
{
    for (const auto &row : a)
    {
        for (int x : row)
            cout << x << ' ';
        cout << '\n';
    }
}

int main()
{
    vector<vector<int>> m1{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> m2{{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};

    cout << "Original Matrix 1:\n";
    printMatrix(m1);
    rotateMatrix90Clockwise(m1);
    cout << "Rotated Matrix 1:\n";
    printMatrix(m1);

    cout << "\nOriginal Matrix 2:\n";
    printMatrix(m2);
    rotateMatrix90Clockwise(m2);
    cout << "Rotated Matrix 2:\n";
    printMatrix(m2);

    return 0;
}
