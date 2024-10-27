#include <iostream>
using namespace std;

// Function to calculate the Greatest Common Divisor (GCD) using the Euclidean algorithm
int gcd(int a, int b)
{
    // Continue looping until either 'a' or 'b' becomes 0
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            // If 'a' is greater than 'b', replace 'a' with 'a % b'
            a = a % b;
        }
        else
        {
            // If 'b' is greater than or equal to 'a', replace 'b' with 'b % a'
            b = b % a;
        }
    }

    // At this point, one of them is zero. The non-zero value is the GCD.
    if (a == 0)
        return b;
    return a;
}

int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "GCD of " << a << " and " << b << " is: " << gcd(a, b) << endl;
    return 0;
}
