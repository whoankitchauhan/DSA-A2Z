#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue; // skip duplicate base element

        int low = i + 1, high = n - 1;
        while (low < high)
        {
            int sum = nums[i] + nums[low] + nums[high];
            if (sum < 0)
            {
                low++;
            }
            else if (sum > 0)
            {
                high--;
            }
            else
            {
                res.push_back({nums[i], nums[low], nums[high]});

                // skip duplicates for low
                while (low < high && nums[low] == nums[low + 1])
                    low++;
                // skip duplicates for high
                while (low < high && nums[high] == nums[high - 1])
                    high--;

                low++;
                high--;
            }
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> testCases = {
        {-1, 0, 1, 2, -1, -4},
        {0, 0, 0, 0},
        {3, 2, 3},
        {1},
        {1, 2, -2, -1}};

    for (int t = 0; t < testCases.size(); t++)
    {
        cout << "Test case " << t + 1 << ": ";
        vector<vector<int>> ans = threeSum(testCases[t]);

        cout << "[";
        for (int i = 0; i < ans.size(); i++)
        {
            cout << "[";
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j];
                if (j < ans[i].size() - 1)
                    cout << ",";
            }
            cout << "]";
            if (i < ans.size() - 1)
                cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}
