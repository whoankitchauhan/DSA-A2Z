#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            unordered_set<long long> hash;
            for (int k = j + 1; k < n; k++)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[k];
                long long fourth = (long long)target - sum;
                if (hash.count(fourth))
                {
                    vector<int> quad = {nums[i], nums[j], nums[k], (int)fourth};
                    sort(quad.begin(), quad.end());
                    s.insert(quad);
                }
                hash.insert(nums[k]);
            }
        }
    }
    return vector<vector<int>>(s.begin(), s.end());
}

int main()
{
    vector<vector<int>> testCases = {
        // Case 1: Mix of positive and negative numbers
        {-3, -1, 0, 2, 4, 5},

        // Case 2: All zeros
        {0, 0, 0, 0, 0, 0},

        // Case 3: Larger dataset with duplicates
        {1, 0, -1, 0, -2, 2, 2, -1, -4},

        // Case 4: No valid quadruplets
        {5, 7, 1, 2, 8, 10},

        // Case 5: Very large numbers to test 64-bit overflow safety
        {1000000000, 1000000000, 1000000000, 1000000000, -1000000000, -1000000000}};

    vector<long long> targets = {
        5,         // Expected: several valid quads
        0,         // Multiple [0, 0, 0, 0] quads
        0,         // Should return unique quads summing to 0
        100,       // Should return empty
        2000000000 // Large sum test
    };

    for (int t = 0; t < testCases.size(); t++)
    {
        cout << "Test case " << t + 1 << ": \n";
        vector<vector<int>> res = fourSum(testCases[t], targets[t]);
        for (auto &quad : res)
        {
            cout << "[";
            for (int i = 0; i < quad.size(); i++)
            {
                cout << quad[i] << (i + 1 < quad.size() ? ", " : "");
            }
            cout << "] ";
        }
        cout << "\n\n";
    }
    return 0;
}
