#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Function to print all divisors of a number
void printDivisors(int n, vector<int> &Divisors)
{
    // Loop through from 1 to sqrt(n)
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            Divisors.push_back(i);
            if (i != n / i)
            {
                Divisors.push_back(n / i);
            }
        }
    }
    sort(Divisors.begin(), Divisors.end());
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;
    vector<int> Divisors;
    printDivisors(num, Divisors);

    // Print the divisors
    cout << "Divisors of " << num << " are: ";
    for (int Divisor : Divisors)
    {
        cout << Divisor << " ";
    }

    return 0;
}

/*
Note - i * i <= n instead of i <= sqrt(n) can be more efficient.

for (int i = 1; i * i <= n; ++i)

Avoiding recomputation: The expression sqrt(n) involves computing the square root of n, which is a computationally more expensive operation than multiplication. By writing i * i <= n, you eliminate the need to repeatedly calculate the square root during every iteration.
*/