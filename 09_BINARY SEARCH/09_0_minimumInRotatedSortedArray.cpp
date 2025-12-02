#include <bits/stdc++.h>
using namespace std;

int minimumInRotatedSortedArray(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] <= nums[high])
        {
            high = mid; // min is in left half including mid
        }
        else
        {
            low = mid + 1; // min is in right half
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
        {4, 5, 6, 7, 0, 1, 2},
        {0, 1, 2, 4, 5, 6, 7},
        {3, 4, 5, 1, 2},
        {2, 3, 4, 5, 6, 7, 1},
        {1}};

    for (int i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << i + 1 << ", Array: ";
        printArray(tests[i]);
        cout << "Answer: " << minimumInRotatedSortedArray(tests[i]) << "\n\n";
    }

    return 0;
}
