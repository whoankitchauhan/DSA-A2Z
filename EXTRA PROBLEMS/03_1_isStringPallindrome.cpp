#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to check if a given string is a palindrome
bool isPalindrome(string s)
{
    int left = 0, right = s.size() - 1;

    while (left < right)
    {
        // Skip non-alphanumeric characters
        if (!isalnum(s[left]))
        {
            left++;
        }
        else if (!isalnum(s[right]))
        {
            right--;
        }
        else
        {
            // Compare characters (case-insensitive)
            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
        }
    }

    return true;
}

// Main function
int main()
{
    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    if (isPalindrome(s))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
