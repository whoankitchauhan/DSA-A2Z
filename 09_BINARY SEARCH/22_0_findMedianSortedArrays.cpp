#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> merged;
    int i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] < nums2[j])
            merged.push_back(nums1[i++]);
        else
            merged.push_back(nums2[j++]);
    }

    while (i < nums1.size())
        merged.push_back(nums1[i++]);
    while (j < nums2.size())
        merged.push_back(nums2[j++]);

    int n = merged.size();
    if (n % 2 == 1)
        return merged[n / 2];

    return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
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
    vector<vector<int>> nums1Tests = {
        {1, 3},
        {1, 2},
        {0, 0},
        {},
        {2}};

    vector<vector<int>> nums2Tests = {
        {2},
        {3, 4},
        {0, 0},
        {1},
        {}};

    vector<double> expected = {
        2.0, // [1,2,3]
        2.5, // [1,2,3,4]
        0.0, // [0,0,0,0]
        1.0, // [1]
        2.0  // [2]
    };

    for (int i = 0; i < nums1Tests.size(); ++i)
    {
        cout << "Test " << i + 1 << "\n";

        cout << "nums1 = ";
        printVector(nums1Tests[i]);
        cout << "\nnums2 = ";
        printVector(nums2Tests[i]);
        cout << "\n";

        double ans = findMedianSortedArrays(nums1Tests[i], nums2Tests[i]);

        cout << "Expected = " << expected[i] << "\n";
        cout << "Actual   = " << ans << "\n\n";
    }

    return 0;
}
