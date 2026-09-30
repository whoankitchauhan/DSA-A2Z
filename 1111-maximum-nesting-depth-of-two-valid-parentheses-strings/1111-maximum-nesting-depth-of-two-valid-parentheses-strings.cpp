class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> answer;
        int depth = 0;

        for (char c : seq) {
            if (c == '(') {
                depth++;

                if (depth % 2 == 1)
                    answer.push_back(0);
                else
                    answer.push_back(1);
            }
            else {
                if (depth % 2 == 1)
                    answer.push_back(0);
                else
                    answer.push_back(1);

                depth--;
            }
        }

        return answer;
    }
};