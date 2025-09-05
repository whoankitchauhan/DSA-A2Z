#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementNby3(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] == nums[i])
                count++;
        }
        if (count > n / 3 && find(result.begin(), result.end(), nums[i]) == result.end())
        {
            result.push_back(nums[i]);
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> testCases = {
        {3, 2, 3},
        {1},
        {1, 2},
        {1, 1, 1, 3, 3, 2, 2, 2}};

    for (auto nums : testCases)
    {
        cout << "Array: ";
        for (int x : nums)
            cout << x << " ";

        cout << " Answer : ";
        for (int x : majorityElementNby3(nums))
            cout << x << " ";
        cout << "\n";
    }
}
