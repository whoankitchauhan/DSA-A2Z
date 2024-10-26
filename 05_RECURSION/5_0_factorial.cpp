#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n <= 1) // Base case: factorial of 0 or 1 is 1
        return 1;
    return n * factorial(n - 1); // Recursive case: n * factorial of (n-1)
}

int main()
{
    cout << "Enter the Number : "; // Max - 13 
    int num;
    cin >> num;
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;
    return 0;
}

/*

For Larger values

#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    if (n <= 1) // Base case: factorial of 0 or 1 is 1
        return 1;
    return n * factorial(n - 1); // Recursive case: n * factorial of (n-1)
}

int main() {
    int num = 20; // Try smaller values for demonstration
    cout << "Factorial of " << num << " is: " << factorial(num) << endl;
    return 0;
}

*/