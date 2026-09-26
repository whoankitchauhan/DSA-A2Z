class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> mp;

        for (auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string answer = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                string key = "";
                i++;

                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                if (mp.count(key))
                    answer += mp[key];
                else
                    answer += "?";
            } else {
                answer += s[i];
            }
        }

        return answer;
    }
};