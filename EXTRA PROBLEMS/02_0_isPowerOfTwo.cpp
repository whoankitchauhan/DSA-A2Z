#include <iostream>
using namespace std;

// Function to check if a number is a power of two
bool isPowerOfTwoLoop(int n)
{
    // A number is a power of two if it is positive and repeatedly divisible by 2
    if (n <= 0)
    {
        return false; // Negative numbers and 0 are not powers of two
    }

    while (n > 1)
    {
        if (n % 2 != 0)
        { // If n is not divisible by 2
            return false;
        }
        n /= 2; // Divide n by 2
    }

    return true; // If we reach 1, n is a power of two
}

// Main function to test the code
int main()
{
    int n;

    cout << "Enter a number to check if it is a power of two: ";
    cin >> n;

    if (isPowerOfTwoLoop(n))
    {
        cout << n << " is a power of two." << endl;
    }
    else
    {
        cout << n << " is NOT a power of two." << endl;
    }

    return 0;
}
