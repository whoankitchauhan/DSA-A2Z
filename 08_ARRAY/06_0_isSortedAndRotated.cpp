#include <iostream>
#include <vector>
using namespace std;

// Function to check if the array is sorted and rotated
bool isSortedAndRotated(vector<int> &nums)
{
    int n = nums.size();
    int rotationCount = 0;

    // Count the number of decreasing points
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            rotationCount++;
        }
    }

    // Check the circular condition (last element > first element)
    if (nums[n - 1] > nums[0])
    {
        rotationCount++;
    }

    // If there is at most one decreasing point, return true
    return rotationCount <= 1;
}

int main()
{
    // Example input arrays
    vector<int> nums1 = {3, 4, 5, 1, 2}; // Expected output: true
    vector<int> nums2 = {2, 1, 3, 4};    // Expected output: false
    vector<int> nums3 = {1, 2, 3};       // Expected output: true

    // Test the function with example inputs
    cout << "Is nums1 sorted and rotated? " << (isSortedAndRotated(nums1) ? "Yes" : "No") << endl;
    cout << "Is nums2 sorted and rotated? " << (isSortedAndRotated(nums2) ? "Yes" : "No") << endl;
    cout << "Is nums3 sorted and rotated? " << (isSortedAndRotated(nums3) ? "Yes" : "No") << endl;

    return 0;
}
