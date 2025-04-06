#include <bits/stdc++.h>
using namespace std;

// Function to find the union of two sorted arrays (without duplicates)
vector<int> findUnion(vector<int> &a, vector<int> &b)
{
    int i = 0, j = 0;   // Two pointers for traversing arrays a and b
    vector<int> result; // Result vector to store union

    // Traverse both arrays until one is completely processed
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            // Avoid adding duplicates
            if (result.empty() || result.back() != a[i])
                result.emplace_back(a[i]);
            i++;
        }
        else
        {
            // Avoid adding duplicates
            if (result.empty() || result.back() != b[j])
                result.emplace_back(b[j]);
            j++;
        }
    }

    // Process remaining elements in array 'a', if any
    while (i < a.size())
    {
        if (result.empty() || result.back() != a[i])
            result.emplace_back(a[i]);
        i++;
    }

    // Process remaining elements in array 'b', if any
    while (j < b.size())
    {
        if (result.empty() || result.back() != b[j])
            result.emplace_back(b[j]);
        j++;
    }

    return result; // Return the final union array
}

int main()
{
    // Test arrays (should be sorted for two-pointer approach to work correctly)
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 3, 5, 6};

    // Call union function
    vector<int> uni = findUnion(a, b);

    // Output the union
    cout << "Union: ";
    for (int x : uni)
        cout << x << " ";
    cout << endl;

    return 0;
}
