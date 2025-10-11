#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> merged;
    int i = 0, j = 0;

    // Merge both arrays
    while (i < m && j < n)
    {
        if (nums1[i] <= nums2[j])
            merged.push_back(nums1[i++]);
        else
            merged.push_back(nums2[j++]);
    }

    // Add remaining elements
    while (i < m)
        merged.push_back(nums1[i++]);
    while (j < n)
        merged.push_back(nums2[j++]);

    // Copy back to nums1
    for (int k = 0; k < m + n; ++k)
        nums1[k] = merged[k];
}

void runTest(vector<int> nums1, int m, vector<int> nums2, int n)
{
    merge(nums1, m, nums2, n);
    for (int num : nums1)
        cout << num << " ";
    cout << endl;
}

int main()
{
    cout << "Test 1: Normal case\n";
    runTest({1, 2, 3, 0, 0, 0}, 3, {2, 5, 6}, 3);

    cout << "Test 2: nums2 smaller elements\n";
    runTest({4, 5, 6, 0, 0, 0}, 3, {1, 2, 3}, 3);

    cout << "Test 3: nums2 empty\n";
    runTest({1, 2, 3}, 3, {}, 0);

    cout << "Test 4: nums1 empty part only, all elements in nums2\n";
    runTest({0, 0, 0}, 0, {2, 5, 6}, 3);

    cout << "Test 5: interleaved merge\n";
    runTest({1, 3, 5, 0, 0, 0}, 3, {2, 4, 6}, 3);

    cout << "Test 6: duplicates\n";
    runTest({1, 2, 2, 0, 0, 0}, 3, {2, 2, 3}, 3);

    return 0;
}
