#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum number of consecutive 1s
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxConsecutive = 0; // Stores the max streak of 1s found so far
    int currentStreak = 0;  // Current count of consecutive 1s

    for (int num : nums)
    {
        if (num == 1)
        {
            currentStreak++;
            maxConsecutive = max(maxConsecutive, currentStreak);
        }
        else
        {
            currentStreak = 0;
        }
    }

    return maxConsecutive;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};

    int result = findMaxConsecutiveOnes(nums);

    cout << "Maximum number of consecutive 1s: " << result << endl;

    return 0;
}
