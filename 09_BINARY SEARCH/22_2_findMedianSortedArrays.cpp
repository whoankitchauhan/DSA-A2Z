#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size(), n2 = nums2.size();
    if (n1 > n2)
        return findMedianSortedArrays(nums2, nums1);

    int low = 0, high = n1;
    int leftSize = (n1 + n2 + 1) / 2;
    int total = n1 + n2;

    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = leftSize - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if (total % 2 == 1)
                return max(l1, l2);
            return (max(l1, l2) + min(r1, r2)) / 2.0;
        }
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
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
