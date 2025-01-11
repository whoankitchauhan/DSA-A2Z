#include <iostream>
#include <vector>
using namespace std;

// Function to find the single non-duplicate element
int singleNonDuplicate(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;

    while (start < end)
    {
        int mid = (start + end) / 2;

        // Ensure mid is even to align with pair indices
        if (mid % 2 == 1)
            mid--;

        // Check if the pair is valid
        if (nums[mid] == nums[mid + 1])
        {
            start = mid + 2; // Single element is after mid
        }
        else
        {
            end = mid; // Single element is at or before mid
        }
    }

    // Start now points to the single element
    return nums[start];
}

// Main function for testing
int main()
{
    // Test cases
    vector<vector<int>> testCases = {
        {1, 1, 2, 3, 3, 4, 4, 8, 8}, // Single element is 2
        {3, 3, 7, 7, 10, 11, 11},    // Single element is 10
        {1, 1, 2},                   // Single element is 2
        {5, 5, 6, 6, 7},             // Single element is 7
        {2}                          // Single element is 2 (only one element in array)
    };

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": ";
        cout << singleNonDuplicate(testCases[i]) << endl;
    }

    return 0;
}
