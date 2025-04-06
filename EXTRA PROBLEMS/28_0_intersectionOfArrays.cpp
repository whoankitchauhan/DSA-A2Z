#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> set1(nums1.begin(), nums1.end()); // Store unique elements of nums1
    unordered_set<int> result;

    for (int num : nums2)
    {
        if (set1.count(num))
        {                       // If num exists in nums1 set
            result.insert(num); // Insert in result set
        }
    }

    // Convert set to vector
    return vector<int>(result.begin(), result.end());
}

int main()
{

    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    vector<int> result = intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
