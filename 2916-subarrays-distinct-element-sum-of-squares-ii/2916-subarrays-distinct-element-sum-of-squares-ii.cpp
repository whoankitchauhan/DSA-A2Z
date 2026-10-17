
class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;
        long long sumSq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r) {
        long long len = r - l + 1;
        long long oldSum = tree[node].sum;

        tree[node].sumSq = (tree[node].sumSq + 2LL * oldSum + len) % MOD;

        tree[node].sum = (oldSum + len) % MOD;
        tree[node].lazy++;
        tree[node].lazy %= MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        long long add = tree[node].lazy;

        int left = node * 2;
        int right = left + 1;

        long long lenLeft = mid - l + 1;
        long long lenRight = r - mid;

        tree[left].sumSq = (tree[left].sumSq + 2LL * add * tree[left].sum +
                            add * add % MOD * lenLeft) %
                           MOD;

        tree[left].sum = (tree[left].sum + add * lenLeft) % MOD;

        tree[left].lazy = (tree[left].lazy + add) % MOD;

        tree[right].sumSq = (tree[right].sumSq + 2LL * add * tree[right].sum +
                             add * add % MOD * lenRight) %
                            MOD;

        tree[right].sum = (tree[right].sum + add * lenRight) % MOD;

        tree[right].lazy = (tree[right].lazy + add) % MOD;

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r);
            return;
        }

        push(node, l, r);

        int mid = l + (r - l) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node].sum = (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

        tree[node].sumSq =
            (tree[node * 2].sumSq + tree[node * 2 + 1].sumSq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node{});

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int p = last[nums[i]];

            update(1, 0, n - 1, p + 1, i);

            ans = (ans + tree[1].sumSq) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};
