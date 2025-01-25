#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if two strings are isomorphic
bool isIsomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;

    // Arrays to track the last seen index of characters in both strings
    vector<int> lastSeenS(256, -1); // Tracks indices for string `s`
    vector<int> lastSeenT(256, -1); // Tracks indices for string `t`

    for (int i = 0; i < s.size(); i++)
    {
        // If the last-seen indices of the current characters don't match, return false
        if (lastSeenS[s[i]] != lastSeenT[t[i]])
            return false;

        // Update the last-seen indices for the current characters
        lastSeenS[s[i]] = i;
        lastSeenT[t[i]] = i;
    }

    return true; // Strings are isomorphic
}

// Driver code
int main()
{
    // Test case 1: isomorphic strings
    string s1 = "egg";
    string t1 = "add";
    cout << "Test case 1: " << (isIsomorphic(s1, t1) ? "Isomorphic" : "Not Isomorphic") << endl;

    // Test case 2: non-isomorphic strings
    string s2 = "foo";
    string t2 = "bar";
    cout << "Test case 2: " << (isIsomorphic(s2, t2) ? "Isomorphic" : "Not Isomorphic") << endl;

    // Test case 3: isomorphic strings
    string s3 = "paper";
    string t3 = "title";
    cout << "Test case 3: " << (isIsomorphic(s3, t3) ? "Isomorphic" : "Not Isomorphic") << endl;

    // Test case 4: non-isomorphic strings
    string s4 = "ab";
    string t4 = "aa";
    cout << "Test case 4: " << (isIsomorphic(s4, t4) ? "Isomorphic" : "Not Isomorphic") << endl;

    return 0;
}
