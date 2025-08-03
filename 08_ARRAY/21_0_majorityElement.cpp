#include <iostream>
#include <vector>
using namespace std;

// Declare your solution class

int majorityElement(vector<int> &nums)
{

    for (int i = 0; i < nums.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] == nums[i])
            {
                count++;
            }
            if (count > nums.size() / 2)
                return nums[i];
        }
    }
    return -1;
}

int main()
{

    vector<vector<int>> testCases = {
        {3, 2, 3},
        {2, 2, 1, 1, 1, 2, 2},
        {1, 1, 1, 2, 3, 4, 1},
        {5, 5, 5, 5, 2, 3},
        {9}};

    for (int i = 0; i < testCases.size(); ++i)
    {
        cout << "Test Case " << i + 1 << ": ";
        for (int num : testCases[i])
            cout << num << " ";
        cout << "\nOutput: " << majorityElement(testCases[i]) << "\n";
        cout << "------------------------\n";
    }

    return 0;
}