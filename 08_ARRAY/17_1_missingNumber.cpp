#include <iostream>
#include <vector>
using namespace std;

// ✅ Approach 2: XOR with two loops
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int xorFull = 0, xorArray = 0;

    // XOR of numbers from 1 to n
    for (int i = 1; i <= n; i++)
    {
        xorFull ^= i;
    }

    // XOR of elements in array
    for (int num : nums)
    {
        xorArray ^= num;
    }

    // XOR difference gives missing number
    return xorFull ^ xorArray;
}

int main()
{
    vector<int> nums = {3, 0, 1};
    cout << "Missing Number: " << missingNumber(nums) << endl;
    return 0;
}
