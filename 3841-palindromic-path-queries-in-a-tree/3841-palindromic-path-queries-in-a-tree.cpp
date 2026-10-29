
class Solution {
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 2, 0) {}

        void add(int i, int value) {
            while (i < (int)bit.size()) {
                bit[i] ^= value;
                i += i & -i;
            }
        }

        void rangeXor(int l, int r, int value) {
            add(l + 1, value);
            add(r + 2, value);
        }

        int query(int i) {
            int result = 0;
            for (; i > 0; i -= i & -i) {
                result ^= bit[i];
            }
            return result;
        }
    };

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s,
                                vector<string>& queries) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        vector<vector<int>> up(LOG, vector<int>(n));
        vector<int> depth(n, 0);
        vector<int> tin(n), tout(n);
        vector<int> parent(n, -1);
        vector<int> subtreeSize(n, 1);
        vector<int> rootMask(n, 0);
        vector<int> order;
        vector<bool> seen(n, false);

        // Iterative DFS: avoid recursion depth issues.
        vector<int> st = {0};
        parent[0] = 0;
        seen[0] = true;

        while (!st.empty()) {
            int u = st.back();
            st.pop_back();

            tin[u] = order.size();
            order.push_back(u);

            up[0][u] = parent[u];

            for (int j = 1; j < LOG; j++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }

            rootMask[u] =
                (u == 0 ? 0 : rootMask[parent[u]]) ^ (1 << (s[u] - 'a'));

            for (int v : adj[u]) {
                if (seen[v])
                    continue;

                seen[v] = true;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            }
        }

        // Calculate subtree sizes in reverse DFS order.
        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            if (u != 0) {
                subtreeSize[parent[u]] += subtreeSize[u];
            }
        }

        for (int u = 0; u < n; u++) {
            tout[u] = tin[u] + subtreeSize[u] - 1;
        }

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b])
                swap(a, b);

            int diff = depth[a] - depth[b];

            for (int j = 0; j < LOG; j++) {
                if (diff & (1 << j)) {
                    a = up[j][a];
                }
            }

            if (a == b)
                return a;

            for (int j = LOG - 1; j >= 0; j--) {
                if (up[j][a] != up[j][b]) {
                    a = up[j][a];
                    b = up[j][b];
                }
            }

            return up[0][a];
        };

        Fenwick fw(n);
        vector<bool> answer;

        for (string& q : queries) {
            string type;
            int u;
            string arg;

            stringstream ss(q);
            ss >> type >> u >> arg;

            if (type == "update") {
                char c = arg[0];

                int delta = (1 << (s[u] - 'a')) ^ (1 << (c - 'a'));

                if (delta != 0) {
                    fw.rangeXor(tin[u], tout[u], delta);
                    s[u] = c;
                }
            } else {
                int v = stoi(arg);
                int w = lca(u, v);

                int maskU = rootMask[u] ^ fw.query(tin[u] + 1);
                int maskV = rootMask[v] ^ fw.query(tin[v] + 1);

                int mask = maskU ^ maskV ^ (1 << (s[w] - 'a'));

                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};
