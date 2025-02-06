#include <iostream>
#include <vector>
using namespace std;

// Function to find all unique combinations that sum to the target using DP
vector<vector<int>> combinationSumDP(vector<int> &candidates, int target)
{
    // dp[i] stores all unique combinations that sum to 'i'
    vector<vector<vector<int>>> dp(target + 1);

    // Base case: There's one way to make sum 0 (empty set)
    dp[0] = {{}};

    // Iterate through each candidate
    for (int num : candidates)
    {
        // Update dp array for targets >= num
        for (int sum = num; sum <= target; sum++)
        {
            // If there are valid ways to form (sum - num), extend them
            for (auto comb : dp[sum - num])
            {
                comb.push_back(num);     // Add the current candidate
                dp[sum].push_back(comb); // Store new combination
            }
        }
    }

    return dp[target]; // Final answer is dp[target]
}

// Driver Code
int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    // Call the function
    vector<vector<int>> result = combinationSumDP(candidates, target);

    // Print the results
    cout << "Combinations using DP : int target = 7\n";
    for (auto &combination : result)
    {
        cout << "[ ";
        for (int num : combination)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}
