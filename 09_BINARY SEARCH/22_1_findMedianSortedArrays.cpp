#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int size1 = nums1.size();
    int size2 = nums2.size();
    int totalSize = size1 + size2;

    int leftMedianIndex = (totalSize - 1) / 2;
    int rightMedianIndex = totalSize / 2;

    int leftMedianValue = 0, rightMedianValue = 0;
    int i = 0, j = 0, mergedIndex = 0;

    while (i < size1 && j < size2)
    {
        int current;
        if (nums1[i] < nums2[j])
            current = nums1[i++];
        else
            current = nums2[j++];

        if (mergedIndex == leftMedianIndex)
            leftMedianValue = current;
        if (mergedIndex == rightMedianIndex)
            rightMedianValue = current;

        mergedIndex++;
    }

    while (i < size1)
    {
        int current = nums1[i++];
        if (mergedIndex == leftMedianIndex)
            leftMedianValue = current;
        if (mergedIndex == rightMedianIndex)
            rightMedianValue = current;
        mergedIndex++;
    }

    while (j < size2)
    {
        int current = nums2[j++];
        if (mergedIndex == leftMedianIndex)
            leftMedianValue = current;
        if (mergedIndex == rightMedianIndex)
            rightMedianValue = current;
        mergedIndex++;
    }

    return (leftMedianValue + rightMedianValue) / 2.0;
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
