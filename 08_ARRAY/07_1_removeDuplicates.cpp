#include <iostream>
#include <vector>
using namespace std;

// Function to remove duplicates using the two-pointer technique
int removeDuplicatesWithTwoPointers(vector<int> &nums)
{
    if (nums.empty())
        return 0; // Handle edge case: empty array

    int uniqueIndex = 0; // Pointer to track the position of unique elements

    // Traverse the array to find unique elements
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] != nums[uniqueIndex])
        {                                // Found a new unique element
            uniqueIndex++;               // Move uniqueIndex forward
            nums[uniqueIndex] = nums[i]; // Update nums with the new unique element
        }
    }

    return uniqueIndex + 1; // Number of unique elements
}

int main()
{
    vector<int> nums = {1, 2, 2, 3, 4, 4, 5};

    cout << "Original array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    int uniqueCount = removeDuplicatesWithTwoPointers(nums);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < uniqueCount; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Number of unique elements: " << uniqueCount << endl;

    return 0;
}
