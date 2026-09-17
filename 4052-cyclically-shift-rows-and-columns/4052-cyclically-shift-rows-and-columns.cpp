class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                    vector<int>& rowShift,
                                    vector<int>& colShift) {
        vector<vector<int>> result(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                // Position after row shift
                int newCol = (j - rowShift[i] + n) % n;

                // Position after column shift
                int newRow = (i - colShift[newCol] + n) % n;

                result[newRow][newCol] = grid[i][j];
            }
        }

        return result;
    }
};