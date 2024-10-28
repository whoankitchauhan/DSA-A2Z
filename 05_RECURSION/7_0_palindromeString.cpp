#include <iostream>
#include <string>
using namespace std;

// Recursive function to check if a string is a palindrome
bool isPalindrome(const string &str, int start, int end)
{
    // Base case: if start index crosses end, all characters matched
    if (start >= end)
    {
        return true;
    }

    // Check if the first and last characters match
    if (str[start] != str[end])
    {
        return false; // Not a palindrome
    }

    // Recursive case: check the remaining substring
    return isPalindrome(str, start + 1, end - 1);
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str, 0, str.length() - 1))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
