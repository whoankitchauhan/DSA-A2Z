class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10)
            return false;
        int turn = 0;
        for (int i = 10; i <= n; i--) {
            n = n - i;
            turn = !turn;
        }
        return turn;
    }
};