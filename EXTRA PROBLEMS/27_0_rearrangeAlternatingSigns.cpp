#include <iostream>
#include <vector>
using namespace std;

// Rearranges the array with alternate positive and negative numbers.
vector<int> rearrangeAlternatingSigns(const vector<int> &nums)
{
    vector<int> result(nums.size(), 0);
    int posIndex = 0; // Next position for positive number
    int negIndex = 1; // Next position for negative number

    for (int num : nums)
    {
        if (num > 0)
        {
            result[posIndex] = num;
            posIndex += 2;
        }
        else
        {
            result[negIndex] = num;
            negIndex += 2;
        }
    }

    return result;
}

// Driver code
int main()
{
    vector<int> nums = {3, 1, -2, -5, 2, -4};
    vector<int> rearranged = rearrangeAlternatingSigns(nums);

    cout << "Rearranged Array: ";
    for (int num : rearranged)
        cout << num << " ";

    return 0;
}
