#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1) // Base cases: Fibonacci(0) = 0, Fibonacci(1) = 1
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2); // Recursive case
}

int main()
{
    int num;
    cout << "Enter the position in the Fibonacci sequence: ";
    cin >> num;

    cout << "Fibonacci(" << num << ") = " << fibonacci(num) << endl;
    return 0;
}
