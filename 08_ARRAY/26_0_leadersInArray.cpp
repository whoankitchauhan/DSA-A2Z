#include <bits/stdc++.h>
using namespace std;

vector<int> leadersInArray(vector<int> &arr)
{
    vector<int> result;
    for (int i = 0; i < arr.size(); i++)
    {
        bool isLeader = true;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] < arr[j])
            {
                isLeader = false;
                break;
            }
        }
        if (isLeader)
        {
            result.push_back(arr[i]);
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> testCases = {
        {16, 17, 4, 3, 5, 2},
        {10, 4, 2, 4, 1},
        {5, 10, 20, 40},
        {30, 10, 10, 5}};

    for (int t = 0; t < testCases.size(); t++)
    {
        cout << "Test Case " << t + 1 << ":\n";
        cout << "Array: ";
        for (int num : testCases[t])
            cout << num << " ";
        cout << "\nLeaders: ";

        vector<int> ans = leadersInArray(testCases[t]);
        for (int x : ans)
            cout << x << " ";
        cout << "\n\n";
    }
    return 0;
}
