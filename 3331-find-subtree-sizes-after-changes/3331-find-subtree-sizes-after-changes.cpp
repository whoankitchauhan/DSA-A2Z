class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {

        int n = parent.size();

        // Step 1: Build the original tree
        vector<vector<int>> children(n);

        for (int i = 1; i < n; i++) {
            children[parent[i]].push_back(i);
        }

        vector<int> newParent = parent;
        vector<int> prevSame(n, -1);
        vector<int> last(26, -1);

        // Step 2: DFS on the original tree
        // {node, state}: state 0 = enter, state 1 = exit
        stack<pair<int, int>> st;
        st.push({0, 0});

        while (!st.empty()) {

            auto [u, state] = st.top();
            st.pop();

            int c = s[u] - 'a';

            if (state == 0) {

                // Save the previous occurrence
                prevSame[u] = last[c];

                // Find the nearest matching ancestor
                if (last[c] != -1) {
                    newParent[u] = last[c];
                }

                // Update the latest occurrence
                last[c] = u;

                // Process exit after all children
                st.push({u, 1});

                for (int i = children[u].size() - 1; i >= 0; i--) {
                    st.push({children[u][i], 0});
                }
            } else {

                // Restore the previous occurrence
                last[c] = prevSame[u];
            }
        }

        // Step 3: Build the modified tree
        vector<vector<int>> newChildren(n);

        for (int i = 1; i < n; i++) {
            newChildren[newParent[i]].push_back(i);
        }

        // Step 4: Get traversal order of modified tree
        vector<int> order;
        stack<int> dfs;
        dfs.push(0);

        while (!dfs.empty()) {

            int u = dfs.top();
            dfs.pop();

            order.push_back(u);

            for (int v : newChildren[u]) {
                dfs.push(v);
            }
        }

        // Step 5: Calculate subtree sizes in reverse order
        vector<int> ans(n, 1);

        for (int i = n - 1; i >= 0; i--) {

            int u = order[i];

            if (newParent[u] != -1) {
                ans[newParent[u]] += ans[u];
            }
        }

        return ans;
    }
};