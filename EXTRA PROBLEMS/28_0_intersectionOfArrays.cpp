#include <bits/stdc++.h>
using namespace std;

/*
    🧠 Approach: HashSet-Based
    -----------------------------------
    - Use an unordered_set to store all unique elements from nums1.
    - Traverse nums2 and check if the element exists in the set.
    - If yes, insert it into the result set to ensure uniqueness.
    - Convert the set to vector and return.

    ✅ Use when:
    - Arrays are unsorted.
    - You want a quick and easy solution with minimal code.

    ⏱ Time Complexity:
    - O(n + m) average (due to hash table lookups)

    💾 Space Complexity:
    - O(n + k), where k = size of intersection
*/

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> set1(nums1.begin(), nums1.end()); // Store unique elements of nums1
    unordered_set<int> result;

    for (int num : nums2)
    {
        if (set1.count(num))
        {
            result.insert(num); // Add to result if exists in nums1
        }
    }

    // Convert result set to vector
    return vector<int>(result.begin(), result.end());
}

int main()
{
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    vector<int> result = intersection(nums1, nums2);

    cout << "Intersection (using HashSet): ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
