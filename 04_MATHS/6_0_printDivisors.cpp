#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Function to find all divisors of a number
vector<int> findDivisors(int n)
{
    vector<int> divisors;

    // Loop through from 1 to sqrt(n)
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i); // i is a divisor
            if (i != n / i)
            {
                divisors.push_back(n / i); // n/i is also a divisor
            }
        }
    }

    // Sort the divisors for better readability
    sort(divisors.begin(), divisors.end());

    return divisors;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    // Get the divisors
    vector<int> divisors = findDivisors(num);

    // Display the divisors
    cout << "Divisors of " << num << " are: ";
    for (int divisor : divisors)
    {
        cout << divisor << " ";
    }
    cout << endl;

    return 0;
}
