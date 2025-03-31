#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); // Sorting helps avoid duplicates easily

    int n = nums.size();

    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue; // Skip duplicate elements

        int left = i + 1, right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicates
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++, right--;
            }
            else if (sum < 0)
                left++; // Increase sum
            else
                right--; // Decrease sum
        }
    }
    return result;
}

// Driver Code
int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = threeSum(nums);

    cout << "Triplets that sum to 0:\n";
    for (const auto &triplet : result)
    {
        cout << "[ ";
        for (int num : triplet)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }
    return 0;
}
