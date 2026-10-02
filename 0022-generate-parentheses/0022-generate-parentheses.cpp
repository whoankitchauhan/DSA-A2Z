class Solution {
public:
    void backtrack(string& sequence, int openRemaining, int closeRemaining,
                   vector<string>& result) {
        if (openRemaining == 0 && closeRemaining == 0) {
            result.push_back(sequence);
            return;
        }

        if (openRemaining > 0) {
            sequence.push_back('(');
            backtrack(sequence, openRemaining - 1, closeRemaining, result);
            sequence.pop_back();
        }

        if (closeRemaining > openRemaining) {
            sequence.push_back(')');
            backtrack(sequence, openRemaining, closeRemaining - 1, result);
            sequence.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string sequence;

        backtrack(sequence, n, n, result);

        return result;
    }
};
