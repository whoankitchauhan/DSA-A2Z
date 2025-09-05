#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> st; // to store unique triplets

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(), temp.end()); // avoid duplicates
                    st.insert(temp);
                }
            }
        }
    }

    return vector<vector<int>>(st.begin(), st.end());
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
