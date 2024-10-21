#include <iostream>
using namespace std;

int reverseNumber(int n)
{
    // Handle negative numbers
    int reverse = 0;
    bool isNegative = (n < 0);
    if (isNegative)
    {
        n = -n; // Convert to positive for processing
    }

    while (n > 0)
    {
        int digit = n % 10;               // Extract the last digit
        reverse = (reverse * 10) + digit; // Append digit to reverse
        n = n / 10;                       // Remove the last digit from n
    }

    // Restore the negative sign if the original number was negative
    return isNegative ? -reverse : reverse;
}

int main()
{
    cout << "Enter the Number: ";
    int num;
    cin >> num;
    cout << "Reverse: " << reverseNumber(num) << endl;
    return 0;
}
