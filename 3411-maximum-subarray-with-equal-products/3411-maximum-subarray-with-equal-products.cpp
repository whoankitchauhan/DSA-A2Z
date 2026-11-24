class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unsigned long long product = 1;
            unsigned long long g = 0;
            unsigned long long l = 1;

            for (int j = i; j < n; j++) {
                product *= nums[j];

                g = gcd(g, nums[j]);

                l = lcm(l, nums[j]);

                if (product == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};