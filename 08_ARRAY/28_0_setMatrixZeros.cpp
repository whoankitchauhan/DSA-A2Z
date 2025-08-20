#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Step 1: Traverse and mark -1 for future zeroes
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark entire row
                for (int k = 0; k < cols; k++)
                {
                    if (matrix[i][k] != 0)
                        matrix[i][k] = -1;
                }
                // mark entire column
                for (int k = 0; k < rows; k++)
                {
                    if (matrix[k][j] != 0)
                        matrix[k][j] = -1;
                }
            }
        }
    }

    // Step 2: Replace all -1 with 0
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
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
