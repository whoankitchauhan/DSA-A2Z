#include <bits/stdc++.h>
using namespace std;

// Function to count subarrays with XOR = k
long countSubarraysWithXor(vector<int> &arr, int k)
{

    int n = arr.size();
    long count = 0;

    for (int i = 0; i < n; ++i)
    { // outer loop
        int currXor = 0;
        for (int j = i; j < n; ++j)
        {
            currXor ^= arr[j];
            if (currXor == k)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> testArrays = {
        {4, 2, 2, 6, 4},
        {5, 6, 7, 8, 9},
        {1, 1, 1, 1}};
    vector<int> ks = {6, 5, 0};
    vector<long> expected = {4, 2, 4};

    for (int t = 0; t < testArrays.size(); ++t)
    {
        cout << "Test case " << t + 1 << ":\n";
        cout << "Input: [ ";
        for (int x : testArrays[t])
            cout << x << " ";
        cout << "], k = " << ks[t] << "\n";

        long result = countSubarraysWithXor(testArrays[t], ks[t]);

        cout << "Output:   " << result << "\n";
        cout << "Expected: " << expected[t] << "\n";
        cout << "-------------------------\n";
    }
    return 0;
}
