#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Function to reverse words in a string
string reverseWords(string s)
{
    string result; // Final result string where reversed words will be stored

    reverse(s.begin(), s.end()); // Step 1: Reverse the entire string

    int i = 0; // Initialize index to traverse through the string
    while (i < s.size())
    {
        // Skip any leading spaces in the string
        while (i < s.size() && s[i] == ' ')
            i++;

        // Extract a word until a space is encountered
        string word;
        while (i < s.size() && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        // Step 2: Reverse the individual word and append it to the result
        if (!word.empty())
        {
            reverse(word.begin(), word.end()); // Reverse the current word
            if (!result.empty())
                result += " "; // Add a space if result already has a word
            result += word;    // Append the reversed word to the result
        }
    }

    return result; // Return the final string with reversed words
}

int main()
{
    // Test cases to validate the function
    string input1 = "  hello world  ";          // Test with leading and trailing spaces
    string input2 = "a good   example";         // Test with multiple spaces between words
    string input3 = "singleword";               // Test with a single word
    string input4 = "   this   is   a test   "; // Test with multiple spaces and words

    // Display results for each test case
    cout << "Input: \"" << input1 << "\"\nOutput: \"" << reverseWords(input1) << "\"\n\n";
    cout << "Input: \"" << input2 << "\"\nOutput: \"" << reverseWords(input2) << "\"\n\n";
    cout << "Input: \"" << input3 << "\"\nOutput: \"" << reverseWords(input3) << "\"\n\n";
    cout << "Input: \"" << input4 << "\"\nOutput: \"" << reverseWords(input4) << "\"\n\n";

    return 0;
}