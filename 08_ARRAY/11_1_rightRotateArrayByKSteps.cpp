#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 3-Reverse Technique
void rightRotateArrayBykSteps(vector<int> &nums, int k)
{
    int n = nums.size();
    k %= n; // Handle cases where k > n

    if (k == 0 || n == 0)
        return; // No rotation needed

    // Step 1: Reverse the entire array
    reverse(nums.begin(), nums.end());

    // Step 2: Reverse the first 'k' elements
    reverse(nums.begin(), nums.begin() + k);

    // Step 3: Reverse the remaining 'n - k' elements
    reverse(nums.begin() + k, nums.end());
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;

    cout << "Original Array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    rightRotateArrayBykSteps(nums, k);

    cout << "Array after Right Rotation by " << k << " positions: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
