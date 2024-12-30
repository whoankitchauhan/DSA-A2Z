#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cout << "Enter a string (lowercase letters only): ";
    cin >> s;

    // Initialize an array to count occurrences of lowercase alphabets
    int hash[26] = {0};

    // Count occurrences of each lowercase alphabet in the input string
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            hash[s[i] - 'a']++;
        }
        else
        {
            cout << "Invalid character '" << s[i] << "' ignored." << endl;
        }
    }

    int q;
    cout << "Enter the number of queries: ";
    cin >> q;

    // Respond to queries regarding the count of specific characters
    while (q--)
    {
        char c;
        cout << "Enter a lowercase character to query its count: ";
        cin >> c;

        // Validate the query character
        if (c >= 'a' && c <= 'z')
        {
            // Output the count of the queried character
            cout << "Count of '" << c << "' in the string: " << hash[c - 'a'] << endl;
        }
        else
        {
            cout << "Invalid character '" << c << "'. Please enter a lowercase letter." << endl;
        }
    }

    return 0;
}
