#include <iostream>
#include <cmath> // For log10
using namespace std;

// Function to count the digits of a number
int countDigits(long long x)
{
    // Handle the special case for zero
    if (x == 0)
    {
        return 1; // Zero has 1 digit
    }

    // Use logarithm to count the digits
    return static_cast<int>(log10(x)) + 1; // Number of digits
}

int main()
{
    long long number;

    cout << "Enter a number: ";
    cin >> number;

    cout << "Number of digits in " << number << " is: " << countDigits(number) << endl;

    return 0;
}

/*
Explanation:
1. Logarithmic Calculation: The log10 function computes the base-10 logarithm of the number.
   The integer part of this logarithm gives the position of the highest digit, and adding 1 gives the total number of digits.

2. Special Case for Zero: The function checks if x is 0 at the beginning since log10(0) is undefined.
   We handle this case by returning 1 because zero has one digit.

3. Efficiency: This method is more efficient than the iterative division method because the logarithm operation is generally computed in constant time O(1).
   Thus, the overall time complexity of the function is also O(1).
*/
