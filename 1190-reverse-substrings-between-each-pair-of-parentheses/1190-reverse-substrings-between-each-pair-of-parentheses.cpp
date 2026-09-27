class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for (char ch : s) {
            if (ch != ')') {
                st.push(ch);
                continue;
            }

            // Collect characters until the matching '('
            string reversedPart;

            while (st.top() != '(') {
                reversedPart += st.top();
                st.pop();
            }

            // Remove '('
            st.pop();

            // Put the reversed characters back onto the stack
            for (char c : reversedPart) {
                st.push(c);
            }
        }

        // Build the final answer
        string result;

        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
