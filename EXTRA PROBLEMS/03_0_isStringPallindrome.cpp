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
        // Move left pointer to the next alphanumeric character
        while (left < right && !isalnum(s[left]))
        {
            left++;
        }
        // Move right pointer to the previous alphanumeric character
        while (left < right && !isalnum(s[right]))
        {
            right--;
        }

        // Check if the characters are equal after converting to lowercase
        if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }

        left++;
        right--;
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
