#include <bits/stdc++.h>
using namespace std;

int minimumInRotatedSortedArrayII(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] < nums[high])
        {
            high = mid; // minimum lies left including mid
        }
        else if (nums[mid] > nums[high])
        {
            low = mid + 1; // minimum lies strictly right
        }
        else
        {
            high--; // nums[mid] == nums[high] -> shrink boundary
        }
    }
    return nums[low];
}

void printArray(const vector<int> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "] ";
}

int main()
{
    vector<vector<int>> tests = {
        {3, 4, 5, 1, 2},
        {2, 2, 2, 0, 1},
        {1, 3, 3},
        {3, 3, 1, 3},
        {1},
        {2, 2, 2, 2, 2}};

    for (int i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << i + 1 << ", Array: ";
        printArray(tests[i]);
        cout << "Answer: " << minimumInRotatedSortedArrayII(tests[i]) << "\n\n";
    }

    return 0;
}
