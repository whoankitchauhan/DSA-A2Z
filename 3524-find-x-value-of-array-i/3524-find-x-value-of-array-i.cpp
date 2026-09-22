class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {

        vector<long long> answer(k, 0);

        // dp[r] = number of subarrays ending at the previous position
        // whose product has remainder r when divided by k.
        vector<long long> dp(k, 0);

        for (int num : nums) {

            vector<long long> newDp(k, 0);

            int remainder = num % k;

            // Start a new subarray containing only the current number.
            newDp[remainder]++;

            // Extend every previous subarray by the current number.
            for (int oldRemainder = 0; oldRemainder < k; oldRemainder++) {

                int newRemainder = (oldRemainder * remainder) % k;

                newDp[newRemainder] += dp[oldRemainder];
            }

            // Move to the next position.
            dp = newDp;

            // Add all subarrays ending at the current position to the answer.
            for (int remainder = 0; remainder < k; remainder++) {
                answer[remainder] += dp[remainder];
            }
        }

        return answer;
    }
};
