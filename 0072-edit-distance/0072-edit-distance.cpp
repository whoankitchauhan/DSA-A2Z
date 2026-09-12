class Solution {
public:
    int solve(string& A, string& B, int i, int j, vector<vector<int>>& dp) {

        // A is finished
        if (i < 0)
            return j + 1;

        // B is finished
        if (j < 0)
            return i + 1;

        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        // Characters are same
        if (A[i] == B[j]) {
            return dp[i][j] = solve(A, B, i - 1, j - 1, dp);
        }

        // Delete A[i]
        int del = solve(A, B, i - 1, j, dp);

        // Insert B[j]
        int ins = solve(A, B, i, j - 1, dp);

        // Replace A[i] with B[j]
        int rep = solve(A, B, i - 1, j - 1, dp);

        return dp[i][j] = 1 + min({del, ins, rep});
    }

    int minDistance(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(word1, word2, n - 1, m - 1, dp);
    }
};
