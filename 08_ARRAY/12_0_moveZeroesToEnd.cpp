#include <iostream>
#include <vector>
using namespace std;

void moveZeroesToEnd(vector<int> &nums)
{
    vector<int> temp;

    // Collect all non-zero elements
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            temp.emplace_back(nums[i]);
        }
    }

    // Place non-zero elements back into the array
    for (int i = 0; i < temp.size(); i++)
    {
        nums[i] = temp[i];
    }

    // Fill the remaining positions with zeros
    for (int i = temp.size(); i < nums.size(); i++)
    {
        nums[i] = 0;
    }
}

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};

    cout << "Original Array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    moveZeroesToEnd(nums);

    cout << "After Moving Zeroes: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
