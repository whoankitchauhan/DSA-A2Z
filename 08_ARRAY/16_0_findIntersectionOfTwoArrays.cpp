#include <bits/stdc++.h>
using namespace std;

// Function to find the intersection of two arrays
vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> result;

    // Sort both arrays to use two-pointer approach
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;

    // Traverse both arrays simultaneously
    while (i < nums1.size() && j < nums2.size())
    {
        if (nums1[i] == nums2[j])
        {
            // Avoid inserting duplicates into result
            if (result.empty() || result.back() != nums1[i])
            {
                result.emplace_back(nums1[i]);
            }
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

// Driver code
int main()
{
    vector<int> nums1 = {1, 2, 2, 3, 4};
    vector<int> nums2 = {2, 2, 3, 5};

    vector<int> intersectionResult = intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : intersectionResult)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
