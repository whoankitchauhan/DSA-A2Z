#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to rearrange array elements alternately (positive, negative) without preserving order
void rearrangeAlternateSign(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = 0;

    // Step 1: Partition - move all negative numbers to the front
    while (j < n)
    {
        if (nums[j] < 0)
        {
            swap(nums[i], nums[j]);
            i++;
        }
        j++;
    }

    // Now, from 0 to i-1 => negative numbers, from i to end => positive numbers
    int neg = 0, pos = i;

    // Step 2: Rearranging alternately by swapping
    // Start swapping every alternate negative with positive
    while (neg < pos && pos < n && nums[neg] < 0)
    {
        swap(nums[neg], nums[pos]);
        neg += 2;
        pos++;
    }

    // ⚠️ Note: This code does NOT preserve the original order of positive or negative numbers.
}

// Driver code
int main()
{
    vector<int> nums = {3, -2, -1, 6, -5, 4, -7, 8};

    cout << "Original array:\n";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    rearrangeAlternateSign(nums);

    cout << "\nRearranged array (alternating + and -, order not preserved):\n";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    return 0;
}
