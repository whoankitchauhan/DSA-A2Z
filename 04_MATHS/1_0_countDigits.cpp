#include <iostream>
using namespace std;

// Function to count the digits of a number
int countDigits(int n)
{
    int count = 0;

    // Handle negative numbers by converting to positive
    if (n < 0)
    {
        n = -n;
    }

    // Handle the case where the number is 0 (which has 1 digit)
    if (n == 0)
    {
        return 1;
    }

    // Loop to count the digits
    while (n != 0)
    {
        n = n / 10; // Remove the last digit
        count++;
    }

    return count;
}

int main()
{
    int number;

    cout << "Enter a number: ";
    cin >> number;  // Ek Dikkat hai ki agar number zero se start ho rha hai too ye isko count nhi kar rha !! iska logic lagana padega 

    cout << "Number of digits in " << number << " is: " << countDigits(number) << endl;

    return 0;
}
