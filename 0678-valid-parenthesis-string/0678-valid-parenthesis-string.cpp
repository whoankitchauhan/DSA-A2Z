class Solution {
public:
    int n;
    vector<vector<int>> dp;

    bool solve(string& s, int index, int balance) {
        if (balance < 0)
            return false;

        if (index == n)
            return balance == 0;

        if (dp[index][balance] != -1)
            return dp[index][balance];

        bool answer;

        if (s[index] == '(') {
            answer = solve(s, index + 1, balance + 1);
        } else if (s[index] == ')') {
            answer = solve(s, index + 1, balance - 1);
        } else {
            answer = solve(s, index + 1, balance + 1) ||
                     solve(s, index + 1, balance - 1) ||
                     solve(s, index + 1, balance);
        }

        return dp[index][balance] = answer;
    }

    bool checkValidString(string s) {
        n = s.size();

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(s, 0, 0);
    }
};