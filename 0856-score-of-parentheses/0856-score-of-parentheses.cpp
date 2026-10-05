class Solution {
public:
    int score(string& s, int left, int right) {
        int answer = 0;
        int balance = 0;
        int start = left;

        for (int i = left; i <= right; i++) {
            if (s[i] == '(')
                balance++;
            else
                balance--;

            if (balance == 0) {
                if (i == start + 1) {
                    answer += 1;
                } else {
                    answer += 2 * score(s, start + 1, i - 1);
                }

                start = i + 1;
            }
        }

        return answer;
    }

    int scoreOfParentheses(string s) { return score(s, 0, s.size() - 1); }
};