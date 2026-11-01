
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minimum = *min_element(nums.begin(), nums.end());

        int ans = 0;

        for (int x : nums) {
            ans += x - minimum;
        }

        return ans;
    }
};
