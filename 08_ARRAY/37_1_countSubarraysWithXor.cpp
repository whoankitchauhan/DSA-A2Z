#include <bits/stdc++.h>
using namespace std;

// Function to count subarrays whose XOR equals targetXor
long countSubarraysWithXor(const vector<int> &arr, int targetXor)
{
    int prefixXor = 0;                     // Tracks the XOR of elements from the start up to the current index
    long subarrayCount = 0;                // Counter for subarrays with XOR == targetXor
    unordered_map<int, int> prefixXorFreq; // Map to store frequencies of prefix XORs encountered

    prefixXorFreq[prefixXor] = 1; // Initialize with XOR 0 (empty subarray)

    // Iterate through the array
    for (int num : arr)
    {
        prefixXor ^= num; // Update the current prefix XOR

        // Find the XOR we need to match targetXor
        int requiredPrefixXor = prefixXor ^ targetXor;

        // Add the frequency of requiredPrefixXor to subarrayCount
        subarrayCount += prefixXorFreq[requiredPrefixXor];

        // Update the frequency map with the current prefix XOR
        prefixXorFreq[prefixXor]++;
    }

    return subarrayCount; 
}

int main()
{
    // Test cases to verify the function
    vector<vector<int>> testArrays = {{4, 2, 2, 6, 4}, {5, 6, 7, 8, 9}, {1, 1, 1, 1}};
    vector<int> targetXors = {6, 5, 0};
    vector<long> expectedResults = {4, 2, 4};

    for (int t = 0; t < testArrays.size(); ++t)
    {
        cout << "Test case " << t + 1 << ":\n";
        cout << "Input: [ ";
        for (int x : testArrays[t])
            cout << x << " ";
        cout << "], targetXor = " << targetXors[t] << "\n";

        long result = countSubarraysWithXor(testArrays[t], targetXors[t]);

        cout << "Output:   " << result << "\n";
        cout << "Expected: " << expectedResults[t] << "\n";
        cout << "-------------------------\n";
    }

    return 0;
}
