class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD = 1e9 + 7;
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; i++) {
            int rightWays = 0;

            for (int j = 0; j < n; j++) {
                int downWays = dp[j];

                if (grid[i][j] == 1) {
                    // Mirror: swap incoming directions.
                    dp[j] = rightWays;
                    rightWays = downWays;
                } else {
                    // Empty cell: both incoming paths can continue.
                    int total = (rightWays + downWays) % MOD;

                    dp[j] = total;
                    rightWays = total;
                }
            }
        }

        return dp[n - 1];
    }
};