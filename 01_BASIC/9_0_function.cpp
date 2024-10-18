#include <bits/stdc++.h>
using namespace std;

// Void function without parameters
void greet()
{
    cout << "Hello Chauhan" << endl;
}

// Void function with parameters
void addAndPrint(int a, int b)
{
    int sum = a + b;
    cout << "Sum: " << sum << endl;
}

// Function with return value
int calculateSum(int x, int y)
{
    return x + y;
}

int main()
{
    // Calling the void function without parameters
    greet();

    // Calling the void function with parameters
    int num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    addAndPrint(num1, num2);

    // Calling the function with return value
    int result = calculateSum(num1, num2);
    cout << "Sum calculated using a function with return value: " << result << endl;

    return 0;
}
