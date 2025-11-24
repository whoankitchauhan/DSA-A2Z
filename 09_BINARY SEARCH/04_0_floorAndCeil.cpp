#include <bits/stdc++.h>
using namespace std;

int floorInSortedArray(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return arr[mid];
        if (arr[mid] < target)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int ceilInSortedArray(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return arr[mid];
        if (arr[mid] > target)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 4, 6, 10};
    vector<int> targets = {5, 1, 0, 12};

    for (int t : targets)
    {
        cout << "Target: " << t
             << " | Floor: " << floorInSortedArray(arr, t)
             << " | Ceil: " << ceilInSortedArray(arr, t) << "\n";
    }
    return 0;
}
