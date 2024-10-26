#include <iostream>
using namespace std;

// Recursive Fibonacci function with added print statements for each call
int fibonacci(int n)
{
    // Base cases: print and return Fibonacci(0) or Fibonacci(1) if n is 0 or 1
    if (n <= 1)
    {
        cout << "Fibonacci(" << n << ") = " << n << endl;
        return n;
    }

    // Recursive calculation with print to show each step
    cout << "Calculating Fibonacci(" << n << ") as Fibonacci(" << n - 1 << ") + Fibonacci(" << n - 2 << ")" << endl;

    int result = fibonacci(n - 1) + fibonacci(n - 2);

    // Print the result before returning
    cout << "Fibonacci(" << n << ") = " << result << endl;

    return result;
}

int main()
{
    int num;
    cout << "Enter the position in the Fibonacci sequence: ";
    cin >> num;

    cout << "Fibonacci(" << num << ") = " << fibonacci(num) << endl;
    return 0;
}
