#include <bits/stdc++.h>
using namespace std;

int findKthPositive(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);

        if (missing < k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return k + low;
}

void printVector(const vector<int> &v)
{
    cout << "[";
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i];
        if (i + 1 < v.size())
            cout << ", ";
    }
    cout << "]";
}

int main()
{
    vector<vector<int>> tests = {
        {2, 3, 4, 7, 11}, // missing in between
        {1, 2, 3, 4},     // missing after last element
        {5, 6, 7},        // missing from start
        {1},              // single element
        {2}               // first number missing
    };

    vector<int> ks = {
        5, // expected 9
        2, // expected 6
        1, // expected 1
        1, // expected 2
        1  // expected 1
    };

    for (int i = 0; i < tests.size(); ++i)
    {
        cout << "Test " << i + 1 << "\n";
        cout << "Array = ";
        printVector(tests[i]);
        cout << "\nK = " << ks[i] << "\n";

        int ans = findKthPositive(tests[i], ks[i]);
        cout << "Kth Missing Positive = " << ans << "\n\n";
    }

    return 0;
}
