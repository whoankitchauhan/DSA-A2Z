#include <iostream>
#include <vector>
using namespace std;
// 2 Pointer Approach
void moveZeroesToEnd(vector<int>& nums) {
    int nonZeroIndex = 0; // Pointer to place the next non-zero element

    // Shift all non-zero elements to the front
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[nonZeroIndex] = nums[i];
            nonZeroIndex++;
        }
    }

    // Fill the remaining positions with zeros
    for (int i = nonZeroIndex; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Original Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    moveZeroesToEnd(nums);

    cout << "After Moving Zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
