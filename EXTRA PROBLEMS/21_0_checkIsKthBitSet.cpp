#include <iostream>
using namespace std;

// Function to check if the k-th bit is set
bool checkKthBit(int n, int k)
{
    // Step 1: Create a bit mask with only the k-th bit set
    int mask = (1 << k); // Shift 1 to the left by k positions

    // Step 2: Perform bitwise AND operation with n and return result
    return (n & mask) != 0;
}

// Driver code to test the function
int main()
{ 
    int n, k;

    // Taking input from the user
    cout << "Enter a number (n): ";
    cin >> n;
    cout << "Enter the bit position (k): ";
    cin >> k;

    // Calling the function and displaying the result
    if (checkKthBit(n, k))
    {
        cout << "The " << k << "-th bit in " << n << " is SET (1)." << endl;
    }
    else
    {
        cout << "The " << k << "-th bit in " << n << " is NOT SET (0)." << endl;
    }

    return 0;
}
