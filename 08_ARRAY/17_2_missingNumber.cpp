#include <iostream>
#include <vector>
using namespace std;

// ✅ Approach 3: Optimized XOR in a single loop
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int xorResult = 0;

    // XOR all indices and elements in one loop
    for (int i = 0; i < n; i++)
    {
        xorResult ^= i ^ nums[i];
    }

    // XOR with n (last number)
    xorResult ^= n;

    return xorResult;
}

int main()
{
    vector<int> nums = {3, 0, 1};
    cout << "Missing Number: " << missingNumber(nums) << endl;
    return 0;
}
