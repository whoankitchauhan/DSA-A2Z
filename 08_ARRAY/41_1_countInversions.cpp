#include <bits/stdc++.h>
using namespace std;
long long mergeAndCount(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int i = low, j = mid + 1;
    long long count = 0;

    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
            count += (mid - i + 1); // all remaining left elements form inversions
        }
    }

    while (i <= mid)
        temp.push_back(arr[i++]);
    while (j <= high)
        temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); ++k)
        arr[low + k] = temp[k];

    return count;
}

long long mergeSortAndCount(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0;
    int mid = (low + high) / 2;
    long long count = 0;
    count += mergeSortAndCount(arr, low, mid);
    count += mergeSortAndCount(arr, mid + 1, high);
    count += mergeAndCount(arr, low, mid, high);
    return count;
}

long long countInversions(vector<int> &arr)
{
    return mergeSortAndCount(arr, 0, arr.size() - 1);
}

int main()
{
    vector<vector<int>> testArrays = {
        {8, 4, 2, 1},     // completely descending
        {1, 20, 6, 4, 5}, // mixed
        {1, 2, 3, 4, 5},  // already sorted
        {5, 4, 3, 2, 1},  // max inversions
        {2, 3, 8, 6, 1},  // random
        {1},              // single element
        {3, 3, 3}         // duplicates (should count 0)
    };

    vector<long long> expected = {
        6, 5, 0, 10, 5, 0, 0};

    for (int t = 0; t < testArrays.size(); ++t)
    {
        cout << "Test Case " << t + 1 << ":\n";
        cout << "Input: [ ";
        for (int x : testArrays[t])
            cout << x << " ";
        cout << "]\n";

        long long Ans = countInversions(testArrays[t]);

        cout << "Result: " << Ans << "\n";
        cout << "Expected: " << expected[t] << "\n";
        cout << "-----------------------------\n";
    }

    return 0;
}
