class Solution {
public:
    bool checkString(string s) {
        int flag = 0;
        for (char a : s) {
            if (a == 'a' && flag == 1) {
                return false;
            }
            if (a == 'b') {
                flag = 1;
            }
        }
        return true;
    }
};