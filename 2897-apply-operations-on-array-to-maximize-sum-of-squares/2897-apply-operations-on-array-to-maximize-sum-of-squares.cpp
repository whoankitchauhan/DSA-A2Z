class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> bits(31, 0);

        for (int num : nums) {
            for (int i = 0; i < 31; i++) {
                if ((num >> i) & 1) {
                    bits[i]++;
                }
            }
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            long long num = 0;

            for (int j = 0; j < 31; j++) {
                if (bits[j] > 0) {
                    num |= (1LL << j);
                    bits[j]--;
                }
            }

            ans = (ans + num * num) % MOD;
        }

        return ans;
    }
};