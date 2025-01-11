#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedArray(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    { // Binary search loop
        int mid = (left + right) / 2;

        // Check if the middle element is the target
        if (nums[mid] == target)
        {
            return mid;
        }

        // Check if the left half is sorted
        if (nums[left] <= nums[mid])
        {
            // If target lies in the left sorted half
            if (nums[left] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            { // Otherwise, search in the right half
                left = mid + 1;
            }
        }
        // Otherwise, the right half must be sorted
        else
        {
            // If target lies in the right sorted half
            if (nums[mid] < target && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            { // Otherwise, search in the left half
                right = mid - 1;
            }
        }
    }
    // If we exit the loop, the target is not in the array
    return -1;
}

int main()
{
    // Test case 1
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "Test Case 1: ";
    int result1 = searchInRotatedArray(nums1, target1);
    if (result1 != -1)
    {
        cout << "Target " << target1 << " found at index " << result1 << "." << endl;
    }
    else
    {
        cout << "Target " << target1 << " not found in the array." << endl;
    }

    // Test case 2
    vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    int target2 = 3;
    cout << "Test Case 2: ";
    int result2 = searchInRotatedArray(nums2, target2);
    if (result2 != -1)
    {
        cout << "Target " << target2 << " found at index " << result2 << "." << endl;
    }
    else
    {
        cout << "Target " << target2 << " not found in the array." << endl;
    }

    // Test case 3
    vector<int> nums3 = {1, 3, 5};
    int target3 = 3;
    cout << "Test Case 3: ";
    int result3 = searchInRotatedArray(nums3, target3);
    if (result3 != -1)
    {
        cout << "Target " << target3 << " found at index " << result3 << "." << endl;
    }
    else
    {
        cout << "Target " << target3 << " not found in the array." << endl;
    }

    return 0;
}
