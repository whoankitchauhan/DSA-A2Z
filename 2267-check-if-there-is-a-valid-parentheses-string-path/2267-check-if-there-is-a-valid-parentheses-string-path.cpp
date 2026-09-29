class Solution {
private:
    int m = 0;
    int n = 0;

public:
    bool valid(int i, int j, int count, vector<vector<char>>& grid,
               vector<vector<vector<int>>>& dp) {

        count += grid[i][j] == '(' ? 1 : -1;

        if (count < 0)
            return false;

        if (i == m - 1 && j == n - 1)
            return count == 0;

        if (dp[i][j][count] != -1)
            return dp[i][j][count];

        bool right = false;
        bool down = false;

        if (j + 1 < n) {
            right = valid(i, j + 1, count, grid, dp);
        }

        if (i + 1 < m) {
            down = valid(i + 1, j, count, grid, dp);
        }

        return dp[i][j][count] = right || down;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int maxCount = m + n;

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(maxCount, -1)));

        if (grid[0][0] == ')')
            return false;

        return valid(0, 0, 0, grid, dp);
    }
};