#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int> &nums)
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

// Driver Code
int main()
{
    vector<int> nums = {3, 3, 4, 2, 3, 3, 3};
    cout << "Majority Element: " << majorityElement(nums) << endl;
    return 0;
}
