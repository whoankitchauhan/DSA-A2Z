#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(const int nums[], int n, int target)
{
    int low = 0, high = n - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int lastOccurrence(const int nums[], int n, int target)
{
    int low = 0, high = n - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int countFreq(const int arr[], int n, int target)
{
    if (n <= 0)
        return 0;
    int first = firstOccurrence(arr, n, target);
    if (first == -1)
        return 0;
    int last = lastOccurrence(arr, n, target);
    return last - first + 1;
}

int main()
{
    vector<vector<int>> tests = {
        {1, 2, 2, 2, 3, 4},
        {5, 7, 7, 8, 8, 10},
        {2, 2, 2, 2, 2},
        {1, 2, 3, 4, 5},
        {}};

    vector<int> targets = {2, 8, 2, 6, 3};

    for (int i = 0; i < tests.size(); ++i)
    {
        vector<int> &arr = tests[i];
        int n = arr.size();
        int target = targets[i];

        int freq = countFreq(arr.data(), n, target);

        cout << "Test " << i + 1
             << " -> Target: " << target
             << " | Frequency: " << freq << "\n";
    }

    return 0;
}
