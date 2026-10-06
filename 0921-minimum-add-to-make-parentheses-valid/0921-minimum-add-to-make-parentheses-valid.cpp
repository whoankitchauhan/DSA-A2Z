class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int missing = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (!st.empty()) {
                    st.pop();
                } else {
                    missing++;
                }
            }
        }

        return missing + st.size();
    }
};