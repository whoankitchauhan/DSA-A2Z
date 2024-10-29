// Iterative Approach (Even More Efficient)
// For optimal efficiency and minimal space usage, we can calculate Fibonacci numbers iteratively:

#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    int a = 0, b = 1, result = 0;
    for (int i = 2; i <= n; i++)
    {
        result = a + b;
        a = b;
        b = result;
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter the position in the Fibonacci sequence: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;
    return 0;
}
