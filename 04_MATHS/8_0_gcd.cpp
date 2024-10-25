#include <iostream>
using namespace std;

// Function to calculate GCD using a brute-force approach
int gcd(int a, int b)
{
    int min_num = (a < b) ? a : b; // Find the smaller of the two numbers
    int result = 1;                // Initialize GCD to 1

    // Check every number from 1 to min_num
    for (int i = 1; i <= min_num; i++)
    {
        if (a % i == 0 && b % i == 0)
        {               // If i divides both a and b
            result = i; // Update result to the current divisor
        }
    }
    return result; // Return the GCD
}

int main()
{
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd(num1, num2) << endl;

    return 0;
}

/*
Staring From Back Side - Efficient
int gcd(int a, int b)
{
    int min_num = (a < b) ? a : b; // Find the smaller of the two numbers
    int result = 1;                // Initialize GCD to 1

    // Check every number from 1 to min_num
    for (int i = min_num; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {               // If i divides both a and b
            result = i; // Update result to the current divisor
            break;
        }
    }
    return result; // Return the GCD
}
*/