#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Majority element using sorting
int majorityElement(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
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
