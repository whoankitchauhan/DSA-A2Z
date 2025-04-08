#include <bits/stdc++.h>
using namespace std;

// Better approach: Count frequency using unordered_map (hashing)
int singleNumber(vector<int> &nums)
{
    unordered_map<int, int> freq;

    // Count frequencies
    for (int num : nums)
    {
        freq[num]++;
    }

    // Return element with frequency 1
    for (auto it : freq)
    {
        if (it.second == 1)
            return it.first;
    }

    return -1; // Should not reach here
}

int main()
{
    vector<int> nums = {2, 2, 1};
    cout << "Single Number (HashMap): " << singleNumber(nums) << endl;
    return 0;
}
