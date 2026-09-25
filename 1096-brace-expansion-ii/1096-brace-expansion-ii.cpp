class Solution {
public:
    unordered_set<string> parse(string& s, int& i) {

        unordered_set<string> result;
        unordered_set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++;

                unordered_set<string> inside = parse(s, i);

                i++; // skip '}'

                unordered_set<string> next;

                for (const string& a : current) {
                    for (const string& b : inside) {
                        next.insert(a + b);
                    }
                }

                current = next;
            }

            else if (s[i] == ',') {

                for (const string& str : current) {
                    result.insert(str);
                }

                current = {""};
                i++;
            }

            else {

                char c = s[i];

                unordered_set<string> next;

                for (const string& str : current) {
                    next.insert(str + c);
                }

                current = next;

                i++;
            }
        }

        for (const string& str : current) {
            result.insert(str);
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        unordered_set<string> result = parse(expression, i);

        vector<string> answer(result.begin(), result.end());

        sort(answer.begin(), answer.end());

        return answer;
    }
};