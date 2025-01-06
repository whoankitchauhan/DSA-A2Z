#include <iostream>
using namespace std;

// Function to check if a number is a power of two
bool isPowerOfTwo(int n)
{
    // A number is a power of two if it is positive and n & (n - 1) == 0
    if (n <= 0)
    {
        return false; // Negative numbers and 0 are not powers of two
    }
    return (n & (n - 1)) == 0; // Check if there is only one set bit
}

// Main function to test the code
int main()
{
    int n;

    cout << "Enter a number to check if it is a power of two: ";
    cin >> n;

    if (isPowerOfTwo(n))
    {
        cout << n << " is a power of two." << endl;
    }
    else
    {
        cout << n << " is NOT a power of two." << endl;
    }

    return 0;
}
