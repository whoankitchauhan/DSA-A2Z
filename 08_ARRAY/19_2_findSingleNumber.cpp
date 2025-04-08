#include <bits/stdc++.h>
using namespace std;

// Optimal approach: XOR all elements to cancel duplicates
int singleNumber(vector<int> &nums)
{
    int xorResult = 0;

    for (int num : nums)
    {
        xorResult ^= num; // Cancels duplicates
    }

    return xorResult; // Remaining number is the unique one
}

int main()
{
    vector<int> nums = {1, 2, 2, 1, 4};
    cout << "Single Number (XOR): " << singleNumber(nums) << endl;
    return 0;
}
