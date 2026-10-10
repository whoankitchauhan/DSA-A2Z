class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);

        long long k = (long long)k1 + k2;
        long long maxDiff = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            total += diff[i];
        }

        if (k >= total)
            return 0;

        long long left = 0, right = maxDiff;

        while (left < right) {
            long long mid = left + (right - left) / 2;
            long long operations = 0;

            for (long long d : diff) {
                if (d > mid)
                    operations += d - mid;
            }

            if (operations <= k)
                right = mid;
            else
                left = mid + 1;
        }

        long long level = left;
        long long operations = 0;
        long long answer = 0;

        for (long long d : diff) {
            if (d > level)
                operations += d - level;

            long long remaining = min(d, level);
            answer += remaining * remaining;
        }

        long long extra = k - operations;

        answer -= extra * (2 * level - 1);

        return answer;
    }
};