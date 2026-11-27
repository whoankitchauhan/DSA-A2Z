
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        // Start with the first three elements
        int ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1;
            int r = n - 1;

            // Find the closest sum using two pointers
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                // Update answer if this sum is closer
                if (abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                }

                // Move left pointer to increase sum
                if (sum < target) {
                    l++;
                }
                // Move right pointer to decrease sum
                else if (sum > target) {
                    r--;
                }
                else {
                    return target; // Exact match found
                }
            }
        }

        return ans;
    }
};
