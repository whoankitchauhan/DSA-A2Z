#include <iostream>
#include <vector>

using namespace std;

int findCandidate(vector<int> &nums)
{
    int candidate = 0, count = 0;

    for (int num : nums)
    {
        if (count == 0)
        {
            candidate = num; // Update candidate
        }
        count += (num == candidate) ? 1 : -1; // Increase or decrease count
    }
    return candidate;
}

int majorityElement(vector<int> &nums)
{
    int candidate = findCandidate(nums);

    // Verification Step: Count occurrences of candidate
    int count = 0;
    for (int num : nums)
    {
        if (num == candidate)
        {
            count++;
        }
    }

    // If candidate appears more than n/2 times, return it; otherwise, return -1
    return (count > nums.size() / 2) ? candidate : -1;
}

// Driver Code
int main()
{
    vector<int> nums = {3, 3, 4, 2, 3, 3, 3};
    int result = majorityElement(nums);

    if (result != -1)
    {
        cout << "Majority Element: " << result << endl;
    }
    else
    {
        cout << "No Majority Element Found" << endl;
    }

    return 0;
}
