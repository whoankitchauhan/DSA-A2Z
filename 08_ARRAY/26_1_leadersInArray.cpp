#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &arr)
{
    int n = arr.size();
    vector<int> result;
    int maxFromRight = arr[n - 1];
    result.push_back(maxFromRight);

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= maxFromRight)
        {
            maxFromRight = arr[i];
            result.push_back(arr[i]);
        }
    }
    reverse(result.begin(), result.end());
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

        vector<int> ans = leaders(testCases[t]);
        for (int x : ans)
            cout << x << " ";
        cout << "\n\n";
    }
    return 0;
}
