#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElementNby3(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> freq;
    vector<int> result;

    for (int num : nums)
    {
        freq[num]++;
    }

    for (auto &it : freq)
    {
        if (it.second > n / 3)
        {
            result.push_back(it.first);
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
