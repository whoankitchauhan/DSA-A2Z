#include <iostream>
#include <string>
using namespace std;

// Recursive function to check if a string is a palindrome using a single pointer
bool isPalindrome(const string &str, int i)
{
    int n = str.length();
    // Base case: if pointer crosses halfway, all characters matched
    if (i >= n - i - 1)
    {
        return true;
    }

    // Check if characters at i and (n - i - 1) positions match
    if (str[i] != str[n - i - 1])
    {
        return false; // Not a palindrome
    }

    // Recursive case: check next pair of characters
    return isPalindrome(str, i + 1);
}

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    if (isPalindrome(str, 0))
    {
        cout << "The string is a palindrome." << endl;
    }
    else
    {
        cout << "The string is not a palindrome." << endl;
    }

    return 0;
}
