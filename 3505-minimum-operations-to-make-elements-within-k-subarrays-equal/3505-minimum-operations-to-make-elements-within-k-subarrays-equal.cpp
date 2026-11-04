
class Solution {
    struct Fenwick {
        int n;
        vector<long long> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void update(int i, long long val) {
            while (i <= n) {
                bit[i] += val;
                i += i & -i;
            }
        }

        long long query(int i) {
            long long sum = 0;

            while (i > 0) {
                sum += bit[i];
                i -= i & -i;
            }

            return sum;
        }

        // Find the smallest index with prefix sum >= k.
        int kth(int k) {
            int idx = 0;

            for (int step = 1 << (31 - __builtin_clz(n)); step > 0;
                 step >>= 1) {

                int next = idx + step;

                if (next <= n && bit[next] < k) {
                    idx = next;
                    k -= bit[next];
                }
            }

            return idx + 1;
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        // Coordinate compression.
        vector<int> vals = nums;
        sort(vals.begin(), vals.end());

        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();

        Fenwick countTree(m), sumTree(m);

        auto update = [&](int val, int delta) {
            int idx =
                lower_bound(vals.begin(), vals.end(), val) - vals.begin() + 1;

            countTree.update(idx, delta);
            sumTree.update(idx, 1LL * val * delta);
        };

        // Calculate the cost of the current window.
        auto getCost = [&]() -> long long {
            int medianIdx = countTree.kth((x + 1) / 2);
            long long median = vals[medianIdx - 1];

            long long leftCount = countTree.query(medianIdx);
            long long leftSum = sumTree.query(medianIdx);

            long long totalSum = sumTree.query(m);

            long long rightCount = x - leftCount;
            long long rightSum = totalSum - leftSum;

            return median * leftCount - leftSum + rightSum -
                   median * rightCount;
        };

        // Calculate every window's cost.
        vector<long long> cost;

        for (int i = 0; i < n; i++) {
            update(nums[i], 1);

            if (i >= x) {
                update(nums[i - x], -1);
            }

            if (i >= x - 1) {
                cost.push_back(getCost());
            }
        }

        // DP with space optimization.
        const long long INF = LLONG_MAX / 4;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, INF);

        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);

            for (int i = 1; i <= n; i++) {
                // Skip current element.
                curr[i] = curr[i - 1];

                // Select window ending at i - 1.
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(curr[i], prev[i - x] + cost[i - x]);
                }
            }

            prev.swap(curr);
        }

        return prev[n];
    }
};
