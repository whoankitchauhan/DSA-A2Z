#include <bits/stdc++.h>
using namespace std;

pair<int, int> findPeakElement(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return {0, nums[0]};

    // left boundary
    if (nums[0] > nums[1])
        return {0, nums[0]};

    // middle part
    for (int i = 1; i < n - 1; ++i)
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
            return {i, nums[i]};
    }

    // right boundary
    return {n - 1, nums[n - 1]};
}

void printArray(const vector<int> &arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i];
        if (i != arr.size() - 1)
            cout << ", ";
    }
    cout << "]";
}

int main()
{
    vector<vector<int>> tests = {
        {1, 2, 3, 1},
        {1, 2, 1},
        {1},
        {3, 4, 5, 1},
        {5, 4, 3, 2, 1},
    };

    for (int i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << i + 1 << ", Array: ";
        printArray(tests[i]);

        auto peak = findPeakElement(tests[i]);
        cout << "  -> Peak Index: " << peak.first
             << ", Peak Value: " << peak.second
             << "\n\n";
    }

    return 0;
}
