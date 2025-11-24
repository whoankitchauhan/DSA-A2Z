#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1, ans = arr.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int upperBound(vector<int> &arr, int target)
{
    int low = 0, high = arr.size() - 1, ans = arr.size();
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 4, 4, 4, 6, 8};

    vector<int> targets = {4, 5, 0, 10};
    cout << "Array : ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << "\n \n";

    for (int t : targets)
    {
        cout << "Target: " << t << "\n";
        cout << "Lower Bound Index: " << lowerBound(arr, t) << "\n";
        cout << "Upper Bound Index: " << upperBound(arr, t) << "\n\n";
    }

    return 0;
}
