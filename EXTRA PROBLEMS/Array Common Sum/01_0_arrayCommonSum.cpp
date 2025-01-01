#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int commonSum(int n1, int n2, vector<int> &arr1, vector<int> &arr2)
    {
        const int MOD = 1e9 + 7; // Define modulo value

        // Step 1: Store all unique elements of arr1 in a set
        unordered_set<int> set1;
        for (int it : arr1)
        {
            set1.insert(it); // Add elements to set
        }

        // Step 2: Find common unique elements and store them in another set
        unordered_set<int> commonSet;
        for (int it : arr2)
        {
            if (set1.count(it))
            {                         // Check if element exists in set1
                commonSet.insert(it); // Add to commonSet
            }
        }

        // Step 3: Calculate the sum of unique common elements
        int sum = 0;
        for (int it : commonSet)
        {
            sum = (sum + it) % MOD; // Add to sum with modulo
        }

        return sum; // Return the final sum
    }
};

int main()
{
    // Example input
    int n1 = 5, n2 = 6;
    vector<int> arr1 = {1, 2, 2, 3, 5};
    vector<int> arr2 = {3, 3, 2, 2, 6, 5};

    // Creating object of the Solution class
    Solution solution;

    // Calling the commonSum function and storing the result
    int result = solution.commonSum(n1, n2, arr1, arr2);

    // Output the result
    cout << "Sum of common unique elements: " << result << endl;

    return 0;
}
