#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Fully Optimaized for Competitive programming
vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> result;

    // Early exit: not enough elements
    if (n < 4)
        return result;

    // Step 1: Sort the array for easier duplicate handling and two-pointer use
    sort(nums.begin(), nums.end());

    // Step 2: Fix the first element of quadruplet
    for (int i = 0; i < n - 3; ++i)
    {
        // Skip duplicates for the first number
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        // Early pruning: if the smallest possible sum is greater than target, break
        if ((long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
            break;

        // If the largest possible sum is still less than target, skip this `i`
        if ((long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
            continue;

        // Step 3: Fix the second element
        for (int j = i + 1; j < n - 2; ++j)
        {
            // Skip duplicates for the second number
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            // More pruning
            if ((long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                break;
            if ((long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2] < target)
                continue;

            // Step 4: Use two-pointer approach for remaining two numbers
            int left = j + 1;
            int right = n - 1;

            // Compute remaining target for left + right
            long long targetSum = (long long)target - nums[i] - nums[j];

            while (left < right)
            {
                long long sum = (long long)nums[left] + nums[right];

                if (sum == targetSum)
                {
                    // Found a valid quadruplet
                    result.push_back({nums[i], nums[j], nums[left], nums[right]});

                    // Skip duplicates for left
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    // Skip duplicates for right
                    while (left < right && nums[right] == nums[right - 1])
                        --right;

                    // Move both pointers inward
                    ++left;
                    --right;
                }
                else if (sum < targetSum)
                {
                    ++left; // Need a bigger sum
                }
                else
                {
                    --right; // Need a smaller sum
                }
            }
        }
    }

    return result;
}

void printResult(const vector<vector<int>> &result)
{
    for (const auto &quad : result)
    {
        cout << "[";
        for (int i = 0; i < quad.size(); ++i)
        {
            cout << quad[i];
            if (i != quad.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }
}
int main()
{
    // Define test cases: {input array, target sum}
    vector<pair<vector<int>, int>> testCases = {
        {{1, 0, -1, 0, -2, 2}, 0},                             // Multiple valid quadruplets
        {{2, 2, 2, 2, 2}, 8},                                  // All identical elements
        {{-3, -1, 0, 2, 4, 5}, 2},                             // Mixed elements
        {{0, 0, 0, 0}, 0},                                     // All zero
        {{-5, 5, 4, -3, 0, 0, 4, -2}, 4},                      // Unordered elements
        {{1000000000, 1000000000, 1000000000, 1000000000}, 0}, // Edge case: large numbers
    };

    for (int i = 0; i < testCases.size(); ++i)
    {
        auto nums = testCases[i].first;
        int target = testCases[i].second;

        // Print test case info
        cout << "Test Case " << i + 1 << ":\n";
        cout << "Input: [";
        for (int j = 0; j < nums.size(); ++j)
        {
            cout << nums[j];
            if (j != nums.size() - 1)
                cout << ", ";
        }
        cout << "], Target = " << target << "\n";

        // Call the function
        auto result = fourSum(nums, target);

        // Output the result
        cout << "Output Quadruplets:\n";
        printResult(result);
        cout << "----------------------\n";
    }

    return 0;
}
