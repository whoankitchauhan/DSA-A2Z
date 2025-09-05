#include <iostream>
#include <vector>
using namespace std;

// Function to generate Pascal's Triangle
vector<vector<int>> generatePascalTriangle(int numRows)
{
    vector<vector<int>> triangle;

    for (int i = 0; i < numRows; ++i)
    {
        vector<int> row(i + 1, 1);
        for (int j = 1; j < i; ++j)
        {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
        triangle.push_back(row);
    }
    return triangle;
}

// Driver code
int main()
{
    int numRows1 = 5;
    int numRows2 = 1;
    int numRows3 = 7;

    vector<vector<int>> result1 = generatePascalTriangle(numRows1);
    vector<vector<int>> result2 = generatePascalTriangle(numRows2);
    vector<vector<int>> result3 = generatePascalTriangle(numRows3);

    // Print results
    cout << "Pascal's Triangle for numRows = " << numRows1 << ":\n";
    for (auto row : result1)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }

    cout << "\nPascal's Triangle for numRows = " << numRows2 << ":\n";
    for (auto row : result2)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }

    cout << "\nPascal's Triangle for numRows = " << numRows3 << ":\n";
    for (auto row : result3)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
