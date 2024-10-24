#include <iostream>
using namespace std;

// Function to calculate GCD using the Euclidean algorithm
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b; // Store b in a temporary variable
        b = a % b;    // Update b to be the remainder of a divided by b
        a = temp;     // Update a to the previous value of b
    }
    return a; // When b becomes 0, a contains the GCD
}

int main()
{
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd(num1, num2) << endl;

    return 0;
}
