#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to check if a number is prime
bool isPrime(int n)
{
    if (n <= 1)
        return false; // 0 and 1 are not prime numbers
    if (n <= 3)
        return true; // 2 and 3 are prime numbers

    // Check divisibility by 2 and 3
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    // Check for factors from 5 to sqrt(n)
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

// Function to print all prime numbers up to a specified limit
void printPrimesUpTo(int limit)
{
    cout << "Prime numbers up to " << limit << " are: ";
    for (int i = 2; i <= limit; i++)
    {
        if (isPrime(i))
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int num;

    cout << "Enter a number to check for primality: ";
    cin >> num;

    if (isPrime(num))
    {
        cout << num << " is a prime number." << endl;
    }
    else
    {
        cout << num << " is not a prime number." << endl;
    }

    cout << "Enter a limit to print all prime numbers up to that limit: ";
    cin >> num;
    printPrimesUpTo(num);

    return 0;
}
