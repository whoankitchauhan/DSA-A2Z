#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the longest common prefix
string longestCommonPrefix(vector<string> &strs)
{
    if (strs.empty()) // Handle the case where the array is empty
        return "";

    string commonPrefix = strs[0]; // Assume the first word as the initial common prefix

    for (int i = 1; i < strs.size(); i++)
    {
        int matchLength = 0; // Length of the common prefix with the current word

        // Compare characters between `commonPrefix` and the current word
        while (matchLength < commonPrefix.size() &&
               matchLength < strs[i].size() &&
               commonPrefix[matchLength] == strs[i][matchLength])
        {
            matchLength++;
        }

        // Reduce `commonPrefix` to the matched length
        commonPrefix = commonPrefix.substr(0, matchLength);

        // If the common prefix is empty, exit early
        if (commonPrefix.empty())
            return "";
    }

    return commonPrefix; // Return the longest common prefix
}

// Driver function to test the implementation
int main()
{
    vector<vector<string>> testCases = {
        {"flower", "flow", "flight"}, // Regular case
        {"dog", "racecar", "car"},    // No common prefix
        {"hello"},                    // Single string
        {},                           // Empty array
        {"match", "match", "match"},  // Strings with exact match
        {"abcd", "ab", "abc"}         // Prefix longer than some strings
    };

    vector<string> expectedResults = {
        "fl",
        "",
        "hello",
        "",
        "match",
        "ab"};

    for (int i = 0; i < testCases.size(); i++)
    {
        cout << "Test Case " << i + 1 << ": ";
        string result = longestCommonPrefix(testCases[i]);
        cout << "Output: \"" << result << "\", Expected: \"" << expectedResults[i] << "\"\n";
        cout << (result == expectedResults[i] ? "PASS\n" : "FAIL\n") << endl;
    }

    return 0;
}
