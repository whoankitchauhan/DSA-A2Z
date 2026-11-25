
class Solution {
public:
    using ll = long long;
    using ull = unsigned long long;

    const ll MOD1 = 1000000007;
    const ll MOD2 = 1000000009;
    const ll BASE = 911382323;

    vector<ll> h1, h2, p1, p2;

    void buildHash(vector<int>& nums) {
        int n = nums.size();

        h1.resize(n + 1, 0);
        h2.resize(n + 1, 0);

        p1.resize(n + 1, 1);
        p2.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {

            h1[i + 1] = (h1[i] * BASE + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE + nums[i]) % MOD2;

            p1[i + 1] = (p1[i] * BASE) % MOD1;
            p2[i + 1] = (p2[i] * BASE) % MOD2;
        }
    }

    ull getHash(int l, int r) {
        int len = r - l + 1;

        ll a = (h1[r + 1] - h1[l] * p1[len] % MOD1 + MOD1) % MOD1;
        ll b = (h2[r + 1] - h2[l] * p2[len] % MOD2 + MOD2) % MOD2;

        return (ull(a) << 32) | ull(b);
    }

    bool check(int len, int n) {

        unordered_map<ull, int> freq;

        for (int i = 0; i + len <= n; i++) {

            ull hash = getHash(i, i + len - 1);

            freq[hash]++;
        }

        for (auto& it : freq) {
            if (it.second == 1) {
                return true;
            }
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {

        int n = nums.size();

        buildHash(nums);

        int low = 1;
        int high = n;
        int ans = n;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
