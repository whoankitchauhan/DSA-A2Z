#include <bits/stdc++.h>
using namespace std;


// I haven't understood this yet, I will understand it in the future.
void rotateMatrix90Clockwise(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int layer = 0; layer < n / 2; layer++)
    {
        int first = layer, last = n - 1 - layer;

        for (int i = first; i < last; i++)
        {
            int offset = i - first;

            int top = matrix[first][i]; // save top element

            // left -> top
            matrix[first][i] = matrix[last - offset][first];

            // bottom -> left
            matrix[last - offset][first] = matrix[last][last - offset];

            // right -> bottom
            matrix[last][last - offset] = matrix[i][last];

            // top -> right
            matrix[i][last] = top;
        }
    }
}

void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
            cout << val << " ";
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

    cout << "\nRotated Matrix (90 degrees clockwise):\n";
    printMatrix(matrix);

    return 0;
}
