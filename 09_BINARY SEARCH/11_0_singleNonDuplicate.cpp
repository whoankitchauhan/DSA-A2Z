#include <bits/stdc++.h>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low < high)
    {
        int mid = (low + high) / 2;

        // ensure mid always points to even index (start of a pair)
        if (mid % 2 == 1)
            mid--;

        if (nums[mid] == nums[mid + 1])
        {
            // left side is perfect pairs → single lies on right side
            low = mid + 2;
        }
        else
        {
            // pair breaks → single is at mid or in left side
            high = mid;
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
        {1, 1, 2, 3, 3, 4, 4, 8, 8},
        {3, 3, 7, 7, 10, 11, 11},
        {1},
        {5, 5, 6},
        {2, 2, 3, 3, 4, 4, 5}};

    for (int i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << i + 1 << ", Array: ";
        printArray(tests[i]);
        cout << " Single Element: "
             << singleNonDuplicate(tests[i])
             << "\n\n";
    }

    return 0;
}
