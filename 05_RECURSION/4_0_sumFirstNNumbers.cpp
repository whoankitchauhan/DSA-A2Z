#include <iostream>
using namespace std;

// Functional approach to calculate the sum of first N numbers
int sumOfFirstN(int n)
{
    if (n == 0) // Base case: when n is 0, return 0
        return 0;
    return n + sumOfFirstN(n - 1); // Recursive call
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Calculate the sum of the first N numbers
    int result = sumOfFirstN(n);

    cout << "The sum of the first " << n << " numbers is: " << result << endl;

    return 0;
}
