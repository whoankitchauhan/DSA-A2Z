class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ')') {
                st.push(s[i]);
            } else {
                string word = "";

                while (st.top() != '(') {
                    word += st.top();
                    st.pop();
                }

                st.pop(); // remove '('

                for (char c : word) {
                    st.push(c);
                }
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};