
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num)
            return "";

        string ans;
        ans.reserve(num);

        int nines = sum / 9;
        int remainder = sum % 9;

        ans.append(nines, '9');

        if (remainder > 0) {
            ans += char('0' + remainder);
        }

        ans.append(num - ans.size(), '0');

        return ans;
    }
};
