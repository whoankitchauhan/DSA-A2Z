#include <bits/stdc++.h>
using namespace std;

// O(n^2)
int subarraySumEqualsK(vector<int> &nums, int k)
{
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
                count++;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> testCases = {
        {1, 1, 1},                 // Example 1
        {1, 2, 3},                 // Example 2
        {3, 4, 7, 2, -3, 1, 4, 2}, // Mixed with negatives
        {-1, -1, 1},               // Negative case
    };
    vector<int> ks = {2, 3, 7, 0};

    for (int t = 0; t < testCases.size(); t++)
    {
        cout << "Test Case " << t + 1 << ": nums = { ";
        for (int x : testCases[t])
            cout << x << " ";
        cout << "}, k = " << ks[t] << ", ";

        cout << "Subarrays : " << subarraySumEqualsK(testCases[t], ks[t]) << "\n";
    }
    return 0;
}
