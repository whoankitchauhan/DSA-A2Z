#include <bits/stdc++.h>
using namespace std;

/*
    🧠 Approach: Two Pointer (Assumes Sorted Arrays)
    ------------------------------------------------------
    - Traverse both sorted arrays using two pointers.
    - If elements match, add to result (ensure no duplicates).
    - Move pointers accordingly.

    ✅ Use when:
    - Arrays are sorted.
    - You want better performance and low space usage.

    ⏱ Time Complexity:
    - O(n + m), where n and m are lengths of nums1 and nums2

    💾 Space Complexity:
    - O(k), where k is size of intersection (output only)

    ❗ Arrays must be sorted for this to work properly.
*/

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    int i = 0, j = 0;
    vector<int> result;

    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            // Avoid duplicates
            if (result.empty() || result.back() != nums1[i])
                result.push_back(nums1[i]);
            i++;
            j++;
        }
        else if (nums1[i] < nums2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return result;
}

int main()
{
    // Must be sorted before calling this approach
    vector<int> nums1 = {1, 2, 2, 3, 4};
    vector<int> nums2 = {2, 2, 3, 5};

    vector<int> result = intersection(nums1, nums2);

    cout << "Intersection (using Two Pointers): ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
