#include <iostream>
#include <cmath>
using namespace std;

// Function to check if a number is an Armstrong number
bool isArmstrong(int n)
{
    int originalNumber = n;
    int sum = 0;
    int numberOfDigits = static_cast<int>(log10(n) + 1); // Calculate number of digits in a single step

    while (n > 0)
    {
        int digit = n % 10;                // Extract last digit
        sum += pow(digit, numberOfDigits); // Add digit^numberOfDigits to sum
        n /= 10;                           // Remove last digit
    }

    // Return true if the sum equals the original number
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
