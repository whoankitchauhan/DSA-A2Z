#include <iostream>
#include <vector>
using namespace std;

// ✅ Approach 3: Optimized XOR in a single loop
int missingNumber(vector<int> &nums)
{
    int xorFull = 0;
    int xorArray = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        xorFull ^= (i + 1);  // XOR of numbers from 1 to n
        xorArray ^= nums[i]; // XOR of given elements
    }

    return xorFull ^ xorArray; // XOR gives the missing number
}

int main()
{
    vector<int> nums = {3, 0, 1};
    cout << "Missing Number: " << missingNumber(nums) << endl;
    return 0;
}
