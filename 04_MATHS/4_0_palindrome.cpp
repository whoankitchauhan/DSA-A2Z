#include <iostream>
using namespace std;

bool isPalindrome(int n)
{
    // Negative numbers cannot be palindromes
    if (n < 0)
    {
        return false;
    }

    int originalNumber = n;
    int reverse = 0;

    // Reverse the number
    while (n > 0)
    {
        int digit = n % 10;               // Extract the last digit
        reverse = (reverse * 10) + digit; // Append it to the reverse
        n = n / 10;                       // Remove the last digit
    }

    // Check if the original number is equal to its reverse
    return (originalNumber == reverse);
}

int main()
{
    cout << "Enter the Number: ";
    int num;
    cin >> num;

    // Output whether the number is a palindrome
    if (isPalindrome(num))
    {
        cout << "The number " << num << " is a Palindrome." << endl;
    }
    else
    {
        cout << "The number " << num << " is not a Palindrome." << endl;
    }

    return 0;
}
