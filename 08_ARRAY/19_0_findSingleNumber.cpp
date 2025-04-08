#include <bits/stdc++.h>
using namespace std;

// Brute force: Check frequency of each element using nested loops
int singleNumber(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[i] == nums[j]) count++;
        }
        if (count == 1) return nums[i]; // Found the element with frequency 1
    }
    return -1; // Should not reach here
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Single Number (Brute Force): " << singleNumber(nums) << endl;
    return 0;
}
