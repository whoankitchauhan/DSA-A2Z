#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// ============================================================================
// YOUR TASK: Implement the function below
// ============================================================================

int countoccurrence(int n, string grid[], string word)
{
    int count = 0;
    int len = word.length();

    // FIXED: Correct direction vectors for all 8 directions
    int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
    int dy[] = {1, -1, 0, 0, 1, -1, 1, -1}; // Fixed: was {1, -1, 0, 0, 1, -1, -1, 1}

    /*
     * Direction mapping:
     * 0: (0,1)  = Right        →
     * 1: (0,-1) = Left         ←
     * 2: (1,0)  = Down         ↓
     * 3: (-1,0) = Up           ↑
     * 4: (1,1)  = Down-Right   ↘
     * 5: (1,-1) = Down-Left    ↙
     * 6: (-1,1) = Up-Right     ↗  <- This was wrong in original
     * 7: (-1,-1)= Up-Left      ↖
     */

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int dir = 0; dir < 8; dir++)
            {
                bool found = true;
                for (int k = 0; k < len; k++)
                {
                    int x = i + k * dx[dir];
                    int y = j + k * dy[dir];
                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] != word[k])
                    {
                        found = false;
                        break;
                    }
                }
                if (found)
                {
                    count++;
                }
            }
        }
    }

    return count;
}

// ============================================================================
// DRIVER CODE - DO NOT MODIFY BELOW THIS LINE
// ============================================================================

void runTest(int testNum, int n, vector<string> &gridVec, string word, int expected)
{
    // Convert vector to array for the function
    string *grid = new string[n];
    for (int i = 0; i < n; i++)
    {
        grid[i] = gridVec[i];
    }

    int result = countoccurrence(n, grid, word);

    cout << "Test " << testNum << ": ";
    if (result == expected)
    {
        cout << "PASSED " << endl;
    }
    else
    {
        cout << "FAILED " << endl;
        cout << "  Expected: " << expected << endl;
        cout << "  Got: " << result << endl;
        cout << "  Grid:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "    " << grid[i] << endl;
        }
        cout << "  Word: " << word << endl;
    }

    delete[] grid;
}

int main()
{
    cout << "=== Word Search in Grid - Test Cases ===" << endl;
    cout << "Find occurrences of a word in all 8 directions" << endl;
    cout << "Palindromes are counted twice!" << endl
         << endl;

    // Test Case 1: Sample from problem
    {
        vector<string> grid = {"ctt", "cat", "cct"};
        runTest(1, 3, grid, "cat", 4);
    }

    // Test Case 2: Sample from problem
    {
        vector<string> grid = {"Jsmpu", "spmuj", "Pmjus", "jumsp", "ujpsM"};
        runTest(2, 5, grid, "jump", 2);
    }

    // Test Case 3: Palindrome test
    {
        vector<string> grid = {"aba", "bcb", "aba"};
        runTest(3, 3, grid, "aba", 8); // 2 horizontal palindromes × 2 directions + 2 vertical palindromes × 2 directions
    }

    // Test Case 4: Diagonal test
    {
        vector<string> grid = {"abc", "def", "ghi"};
        runTest(4, 3, grid, "aei", 1); // Main diagonal
    }

    // Test Case 5: All directions test
    {
        vector<string> grid = {"xdogx", "xoaox", "xgaox", "xoxox", "xxxxx"};
        runTest(5, 5, grid, "dog", 2); // Horizontal and vertical
    }

    // Test Case 6: Single character
    {
        vector<string> grid = {"aaa", "aaa", "aaa"};
        runTest(6, 3, grid, "a", 72); // 9 positions × 8 directions = 72 (single char found everywhere)
    }

    // Test Case 7: Word not found
    {
        vector<string> grid = {"abc", "def", "ghi"};
        runTest(7, 3, grid, "xyz", 0);
    }

    // Test Case 8: Overlapping words
    {
        vector<string> grid = {"cat", "ata", "tac"};
        runTest(8, 3, grid, "cat", 4); // Horizontal (both directions) + both diagonals
    }

    cout << endl
         << "=== All tests completed! ===" << endl;
    cout << "Implement the countoccurrence function to pass all tests." << endl;

    return 0;
}