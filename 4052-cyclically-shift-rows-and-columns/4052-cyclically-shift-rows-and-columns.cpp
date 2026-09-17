class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                    vector<int>& rowShift,
                                    vector<int>& colShift) {
        // Shift rows
        for (int i = 0; i < n; i++) {
            for (int shift = 0; shift < rowShift[i]; shift++) {

                int first = grid[i][0];

                for (int j = 0; j < n - 1; j++) {
                    grid[i][j] = grid[i][j + 1];
                }

                grid[i][n - 1] = first;
            }
        }

        // Shift columns
        for (int j = 0; j < n; j++) {
            for (int shift = 0; shift < colShift[j]; shift++) {

                int first = grid[0][j];

                for (int i = 0; i < n - 1; i++) {
                    grid[i][j] = grid[i + 1][j];
                }

                grid[n - 1][j] = first;
            }
        }

        return grid;
    }
};