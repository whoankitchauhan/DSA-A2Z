#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find all combinations
void findCombinations(vector<int> &candidates, int remainingTarget, vector<vector<int>> &result, vector<int> &currentCombination, int startIndex)
{
    // Base case: If remaining target is 0, we found a valid combination
    if (remainingTarget == 0)
    {
        result.push_back(currentCombination);
        return;
    }

    // Iterate through candidates, allowing repeated selection
    for (int i = startIndex; i < candidates.size(); i++)
    {
        // If the current number exceeds the remaining target, stop further checks
        if (candidates[i] > remainingTarget)
            break;

        // Choose the number
        currentCombination.push_back(candidates[i]);

        // Recur with reduced target, allowing repeated use of the same number
        findCombinations(candidates, remainingTarget - candidates[i], result, currentCombination, i);

        // Backtrack: Remove last number to explore other possibilities
        currentCombination.pop_back();
    }
}

// Function to find all unique combinations that sum up to target
vector<vector<int>> combinationSumBacktracking(vector<int> &candidates, int target)
{
    vector<vector<int>> result;                 // Stores all valid combinations
    vector<int> currentCombination;             // Tracks the current combination being built
    sort(candidates.begin(), candidates.end()); // Sorting helps in optimization
    findCombinations(candidates, target, result, currentCombination, 0);
    return result;
}

// Driver Code
int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    // Call the function
    vector<vector<int>> result = combinationSumBacktracking(candidates, target);

    // Print the results
    cout << "Combinations using Backtracking : target = 7 \n";
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
