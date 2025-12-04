#include <bits/stdc++.h>
using namespace std;

pair<int, int> findPeakElement(vector<int> &nums)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (nums[mid] < nums[mid + 1])
        {
            low = mid + 1; // go right (uphill)
        }
        else
        {
            high = mid; // go left (mid might be peak)
        }
    }
    return {low, nums[low]}; // peak index and its value
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
        cout << " -> Peak Index: " << peak.first
             << ", Peak Value: " << peak.second
             << "\n\n";
    }

    return 0;
}
