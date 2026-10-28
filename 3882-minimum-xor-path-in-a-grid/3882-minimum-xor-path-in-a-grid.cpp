
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        const int X = 1024;

        vector<vector<char>> dp(n, vector<char>(X, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<char> cur(X, false);

                if (i == 0 && j == 0) {
                    cur[grid[i][j]] = true;
                } else {
                    // Paths arriving from above.
                    if (i > 0) {
                        for (int x = 0; x < X; x++) {
                            if (dp[j][x])
                                cur[x ^ grid[i][j]] = true;
                        }
                    }

                    // Paths arriving from the left.
                    if (j > 0) {
                        for (int x = 0; x < X; x++) {
                            if (dp[j - 1][x])
                                cur[x ^ grid[i][j]] = true;
                        }
                    }
                }

                dp[j] = move(cur);
            }
        }

        for (int x = 0; x < X; x++) {
            if (dp[n - 1][x])
                return x;
        }

        return -1;
    }
};
