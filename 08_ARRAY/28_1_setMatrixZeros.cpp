#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> row(rows, 1), col(cols, 1);

    // Step 1: Mark rows and cols that should be zero
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 0;
                col[j] = 0;
            }
        }
    }

    // Step 2: Update matrix
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (row[i] == 0 || col[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<vector<int>>> testCases = {
        {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}},
        {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}},
        {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}};

    for (auto &matrix : testCases)
    {
        setZeroes(matrix);
        for (auto &row : matrix)
        {
            for (int val : row)
                cout << val << " ";
            cout << endl;
        }
        cout << "----" << endl;
    }
}
