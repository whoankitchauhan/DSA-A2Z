#include <iostream>
#include <vector>
using namespace std;

// Function to perform right rotation of an array by k positions
void rightRotateArrayBykSteps(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n == 0 || k == 0 || k % n == 0)
    {
        return; // No rotation needed
    }

    k %= n; // Handle cases where k > n

    // Step 1: Store the last 'k' elements in a temporary array
    vector<int> temp(k);
    for (int i = 0; i < k; i++)
    {
        temp[i] = nums[n - k + i];
    }

    // Step 2: Shift the remaining elements to the right
    for (int i = n - 1; i >= k; i--)
    {
        nums[i] = nums[i - k];
    }

    // Step 3: Place the elements from the temporary array at the start
    for (int i = 0; i < k; i++)
    {
        nums[i] = temp[i];
    }
}

// Main function for testing
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
