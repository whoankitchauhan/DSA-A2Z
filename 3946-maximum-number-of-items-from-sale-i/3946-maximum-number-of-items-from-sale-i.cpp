
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        // Step 1: Calculate free items for each item
        vector<int> freeItems(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeItems[i]++;
                }
            }
        }

        // Step 2: DP
        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {

            int price = items[i][1];
            int free = freeItems[i];

            vector<int> cur = dp;

            for (int b = price; b <= budget; b++) {

                // Option 1: First purchase of this item
                int first = dp[b - price] + 1 + free;

                // Option 2: Additional purchase
                int again = cur[b - price] + 1;

                cur[b] = max({dp[b], first, again});
            }

            dp = cur;
        }

        return dp[budget];
    }
};
