class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        if (nums[0] == 0)
            return 0;
        for (int i = 1; i < nums.size(); i++) {
            int sum = 0;
            int temp = nums[i];
            while (temp) {
                sum += temp % 10;
                temp = temp / 10;
            }
            if (sum == i) {
                return i;
            }
        }
        return -1;
    }
};