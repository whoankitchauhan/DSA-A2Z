class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool solve(int i, int j, int balance, vector<vector<char>>& grid) {
        if (balance < 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return balance == 0;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool right = false;
        bool down = false;

        if (j + 1 < n) {
            int nextBalance = balance + (grid[i][j + 1] == '(' ? 1 : -1);
            right = solve(i, j + 1, nextBalance, grid);
        }

        if (i + 1 < m) {
            int nextBalance = balance + (grid[i + 1][j] == '(' ? 1 : -1);
            down = solve(i + 1, j, nextBalance, grid);
        }

        return dp[i][j][balance] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        int maxBalance = m + n;

        dp.assign(m, vector<vector<int>>(
            n, vector<int>(maxBalance + 1, -1)
        ));

        int balance = 1;

        return solve(0, 0, balance, grid);
    }
};