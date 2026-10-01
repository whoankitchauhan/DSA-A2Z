class Solution {
public:
    bool isValid(string s) {
        while (true) {
            int oldSize = s.size();

            for (int i = 0; i + 1 < s.size(); i++) {
                string pair = s.substr(i, 2);

                if (pair == "()" || pair == "[]" || pair == "{}") {
                    s.erase(i, 2);
                    break;
                }
            }

            if (s.size() == oldSize)
                break;
        }

        return s.empty();
    }
};