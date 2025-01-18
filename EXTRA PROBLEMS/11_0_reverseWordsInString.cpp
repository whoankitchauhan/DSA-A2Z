#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function to reverse the words in a string
string reverseWords(string s)
{
    string result;
    // Step 1: Reverse the entire string
    reverse(s.begin(), s.end());

    for (int i = 0; i < s.size(); i++)
    {
        string word;

        // Extract each word by skipping spaces
        while (i < s.size() && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        // Reverse the extracted word and add it to the result
        reverse(word.begin(), word.end());
        if (!word.empty())
            result += " " + word; // Add a space before the word
    }

    // Remove the leading space and return the result
    return result.substr(1);
}

int main()
{
    // Test cases
    string test1 = "the sky is blue";
    string test2 = "  hello world  ";  // Leading and trailing spaces
    string test3 = "a good   example"; // Multiple spaces between words
    string test4 = "single";           // Single word
    string test5 = "";                 // Empty string

    cout << "Test Case 1: \"" << test1 << "\" -> \"" << reverseWords(test1) << "\"" << endl;
    cout << "Test Case 2: \"" << test2 << "\" -> \"" << reverseWords(test2) << "\"" << endl;
    cout << "Test Case 3: \"" << test3 << "\" -> \"" << reverseWords(test3) << "\"" << endl;
    cout << "Test Case 4: \"" << test4 << "\" -> \"" << reverseWords(test4) << "\"" << endl;
    cout << "Test Case 5: \"" << test5 << "\" -> \"" << reverseWords(test5) << "\"" << endl;

    return 0;
}
