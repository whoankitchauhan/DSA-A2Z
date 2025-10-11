#include <bits/stdc++.h>
using namespace std;

// Function to count subarrays with XOR = k
long countSubarraysWithXor(vector<int> &arr, int k)
{
    unordered_map<int, int> freq; // frequency of prefixXor values
    int prefixXor = 0;
    long count = 0;
    int n = arr.size();

    for (int i = 0; i < n; ++i)
    {
        prefixXor ^= arr[i];

        // if subarray [0..i] itself has XOR = k
        if (prefixXor == k)
        {
            count++;
        }

        // check if there exists a prefix such that:
        // prefixXor ^ thatPrefix = k  -> subarray with XOR = k
        int need = prefixXor ^ k;
        if (freq.find(need) != freq.end())
        {
            count += freq[need];
        }

        // store/update current prefixXor frequency
        freq[prefixXor]++;
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
