/*
An Armstrong number (also known as a narcissistic number) is a number that is equal to the sum of its own digits raised to the power of the number of digits.
*/

#include <iostream>
#include <cmath> // For pow() function
using namespace std;

// Function to check if a number is an Armstrong number
bool isArmstrong(int n)
{
    int originalNumber = n;
    int sum = 0;
    int numberOfDigits = 0;

    // Find the number of digits in the number
    int temp = n;
    while (temp != 0)
    {
        temp /= 10;
        numberOfDigits++;
    }

    // Calculate the sum of digits raised to the power of numberOfDigits
    temp = n;
    while (temp != 0)
    {
        int digit = temp % 10;
        sum += pow(digit, numberOfDigits);
        temp /= 10;
    }

    // Check if the sum is equal to the original number
    return (sum == originalNumber);
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if (isArmstrong(num))
    {
        cout << num << " is an Armstrong number." << endl;
    }
    else
    {
        cout << num << " is not an Armstrong number." << endl;
    }

    return 0;
}
