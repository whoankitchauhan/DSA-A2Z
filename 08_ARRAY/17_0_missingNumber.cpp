#include <iostream>
#include <vector>
using namespace std;

// ✅ Approach 1: Using sum formula
int missingNumber(vector<int> &nums)
{
    int n = nums.size();            // Since one number is missing, size is n
    int totalSum = n * (n + 1) / 2; // Sum of first n natural numbers
    int arraySum = 0;

    // Calculate the sum of elements in the array
    for (int num : nums)
    {
        arraySum += num;
    }

    // Missing number is the difference
    return totalSum - arraySum;
}

int main()
{
    vector<int> nums = {3, 0, 1};
    cout << "Missing Number: " << missingNumber(nums) << endl;
    return 0;
}
