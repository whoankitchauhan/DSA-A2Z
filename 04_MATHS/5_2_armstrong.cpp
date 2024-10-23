#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Function to check if a number is an Armstrong number
bool isArmstrong(int n)
{
    int k = to_string(n).size(); // Find the number of digits
    int s = 0;                   // To store the sum of powers

    // Calculate the sum of digits raised to the power of k

    for (int x = n; x; x /= 10)
    {
        s += pow(x % 10, k);
    }

    // Return true if the sum of powers equals the original number
    return s == n;
}

int main()
{
    int num;

    // Input from user
    cout << "Enter a number: ";
    cin >> num;

    // Check if the number is an Armstrong number and display the result
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

/*

    for (int x = n; x; x /= 10)
    {
        int digit = x % 10;
        int pow_result = 1;

        // Calculate the power of the digit
        for (int i = 0; i < k; ++i)
        {
            pow_result *= digit;
        }

        s += pow_result;
    }



Why This Might Be Better:
- Avoids pow() overhead: Computing the power manually can be faster and avoids potential floating-point precision issues.

*/