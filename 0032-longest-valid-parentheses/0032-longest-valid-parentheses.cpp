class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int answer = 0;

        for (int i = 1; i < n; i++) {

            if (s[i] == ')') {

                if (s[i - 1] == '(') {
                    dp[i] = 2;

                    if (i >= 2)
                        dp[i] += dp[i - 2];
                }

                else {
                    int open = i - dp[i - 1] - 1;

                    if (open >= 0 && s[open] == '(') {
                        dp[i] = dp[i - 1] + 2;

                        if (open >= 1)
                            dp[i] += dp[open - 1];
                    }
                }

                answer = max(answer, dp[i]);
            }
        }

        return answer;
    }
};