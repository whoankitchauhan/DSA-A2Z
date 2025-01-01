#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int commonSum(int n1, int n2, vector<int> &arr1, vector<int> &arr2)
    {
        const int MOD = 1e9 + 7; // Define modulo value

        // Step 1: Store all unique elements of arr1 in a set
        unordered_set<int> elementsInArr1;
        for (int num : arr1)
        {
            elementsInArr1.emplace(num); // Insert unique elements
        }

        // Step 2: Calculate sum of unique common elements
        int sum = 0;
        unordered_set<int> addedElements; // To ensure each common element is added only once
        for (int num : arr2)
        {
            // If the element is in arr1 and hasn't been added before
            if (elementsInArr1.count(num) && !addedElements.count(num))
            {
                sum = (sum + num) % MOD;    // Add to sum with modulo
                addedElements.emplace(num); // Mark as added
            }
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
