#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool firstRow = false, firstCol = false;

    // Step 1: Check for zeroes and mark first row/col
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (i == 0)
                    firstRow = true;
                if (j == 0)
                    firstCol = true;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Step 2: Mark inside matrix
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Step 3: Handle first row
    if (firstRow)
    {
        for (int j = 0; j < cols; j++)
            matrix[0][j] = 0;
    }

    // Step 4: Handle first col
    if (firstCol)
    {
        for (int i = 0; i < rows; i++)
            matrix[i][0] = 0;
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
