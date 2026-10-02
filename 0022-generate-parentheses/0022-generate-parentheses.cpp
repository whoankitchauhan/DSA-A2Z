class Solution {
public:
    void backtrack(string& current, int open, int close,
                   vector<string>& result) {
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }

        if (open > 0) {
            current.push_back('(');
            backtrack(current, open - 1, close, result);
            current.pop_back();
        }

        if (close > open) {
            current.push_back(')');
            backtrack(current, open, close - 1, result);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;

        backtrack(current, n, n, result);

        return result;
    }
};