#include <iostream>
using namespace std;

bool isPalindrome(int n)
{
    // Negative numbers are not palindromes
    if (n < 0)
        return false;

    // Numbers that end with 0 and are not 0 are not palindromes
    if (n != 0 && n % 10 == 0)
        return false;

    int reversedHalf = 0;

    // Reverse half of the number
    while (n > reversedHalf)
    {
        int digit = n % 10;
        reversedHalf = reversedHalf * 10 + digit;
        n = n / 10;
    }

    // Check if the original first half is equal to the reversed second half
    return (n == reversedHalf || n == reversedHalf / 10);
}

int main()
{
    cout << "Enter the Number: ";
    int num;
    cin >> num;

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
