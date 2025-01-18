#include <iostream>
#include <algorithm>
using namespace std;

string reverseWords(string &s)
{
    // Step 1: Remove leading, trailing, and extra spaces
    int i = 0, j = 0, n = s.size();

    while (j < n)
    {
        // Skip leading spaces
        while (j < n && s[j] == ' ')
            j++;
        // Copy valid characters (a word)
        while (j < n && s[j] != ' ')
            s[i++] = s[j++];
        // Skip trailing spaces between words
        while (j < n && s[j] == ' ')
            j++;
        // Add a single space between words
        if (j < n)
            s[i++] = ' ';
    }

    s.resize(i); // Resize string to remove extra characters at the end

    // Step 2: Reverse the entire string
    reverse(s.begin(), s.end());

    // Step 3: Reverse each word
    int start = 0;
    for (int end = 0; end <= s.size(); ++end)
    {
        if (end == s.size() || s[end] == ' ')
        {                                                // Word boundary
            reverse(s.begin() + start, s.begin() + end); // Reverse the word
            start = end + 1;                             // Move to the next word
        }
    }

    return s;
}

int main()
{
    // Test cases
    string s1 = "   the   sky   is blue   ";
    cout << "Reversed words: \"" << reverseWords(s1) << "\"" << endl;

    string s2 = "   Hello world   ";
    cout << "Reversed words: \"" << reverseWords(s2) << "\"" << endl;

    string s3 = "a good   example";
    cout << "Reversed words: \"" << reverseWords(s3) << "\"" << endl;

    string s4 = "singleword";
    cout << "Reversed words: \"" << reverseWords(s4) << "\"" << endl;

    string s5 = "   ";
    cout << "Reversed words: \"" << reverseWords(s5) << "\"" << endl;

    return 0;
}
