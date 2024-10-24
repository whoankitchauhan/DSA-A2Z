#include <iostream>
#include <vector>

using namespace std;

// Function to find all prime numbers up to a specified limit using the Sieve of Eratosthenes
vector<int> sieveOfEratosthenes(int limit)
{
    // Create a boolean vector to track prime status of each number
    vector<bool> isPrime(limit + 1, true); // Initialize all entries as true
    isPrime[0] = isPrime[1] = false;       // 0 and 1 are not prime numbers

    // Iterate from 2 to the square root of the limit
    for (int i = 2; i * i <= limit; i++)
    {
        // If the number is still marked as prime
        if (isPrime[i])
        {
            // Mark all multiples of i as not prime, starting from i*i
            for (int j = i * i; j <= limit; j += i)
            {
                isPrime[j] = false; // Set the multiple to false
            }
        }
    }

    // Collect all prime numbers into a vector
    vector<int> primes;
    for (int i = 2; i <= limit; i++)
    {
        if (isPrime[i])
        {                        // If the number is marked as prime
            primes.push_back(i); // Add it to the primes vector
        }
    }

    return primes; // Return the vector of prime numbers
}

int main()
{
    int num;

    // Prompt the user for input
    cout << "Enter a limit to print all prime numbers up to that limit: ";
    cin >> num;

    // Call the function to get all prime numbers up to the specified limit
    vector<int> primes = sieveOfEratosthenes(num);

    // Display the prime numbers
    cout << "Prime numbers up to " << num << " are: ";
    for (int prime : primes)
    {
        cout << prime << " "; // Print each prime number
    }
    cout << endl;

    return 0; // Indicate successful execution
}
