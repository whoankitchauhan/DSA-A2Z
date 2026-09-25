class Solution {
public:
    set<string> parse(string& s, int& i) {
        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {
                i++;

                set<string> inside = parse(s, i);

                i++; // skip '}'

                set<string> next;

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

                set<string> next;

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

        set<string> result = parse(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};