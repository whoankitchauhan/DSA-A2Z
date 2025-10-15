#include <bits/stdc++.h>
using namespace std;

long long countInversions(vector<int> &arr)
{
    int n = arr.size();
    long long count = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[i] > arr[j])
                ++count;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> testArrays = {
        {8, 4, 2, 1},     // completely descending
        {1, 20, 6, 4, 5}, // mixed
        {1, 2, 3, 4, 5},  // already sorted
        {5, 4, 3, 2, 1},  // max inversions
        {2, 3, 8, 6, 1},  // random
        {1},              // single element
        {3, 3, 3}         // duplicates (should count 0)
    };

    vector<long long> expected = {
        6, 5, 0, 10, 5, 0, 0};

    for (int t = 0; t < testArrays.size(); ++t)
    {
        cout << "Test Case " << t + 1 << ":\n";
        cout << "Input: [ ";
        for (int x : testArrays[t])
            cout << x << " ";
        cout << "]\n";

        long long Ans = countInversions(testArrays[t]);

        cout << "Result: " << Ans << "\n";
        cout << "Expected: " << expected[t] << "\n";
        cout << "-----------------------------\n";
    }

    return 0;
}
