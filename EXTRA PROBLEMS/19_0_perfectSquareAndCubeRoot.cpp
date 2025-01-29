#include <iostream>
#include <cmath> // For sqrt() and cbrt()

using namespace std;

// Function to check if a number is a perfect square
bool isPerfectSquare(int number)
{
    if (number < 0)
        return false;                               // Negative numbers can't be perfect squares
    int sqrtValue = static_cast<int>(sqrt(number)); // Compute square root
    return (sqrtValue * sqrtValue == number);       // Check if squaring it gives original number
}

// Function to check if a number is a perfect cube
bool isPerfectCube(int number)
{
    int cbrtValue = static_cast<int>(cbrt(number));       // Compute cube root
    return (cbrtValue * cbrtValue * cbrtValue == number); // Check if cubing it gives original number
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (isPerfectSquare(number))
    {
        cout << number << " is a Perfect Square." << endl;
    }
    else
    {
        cout << number << " is NOT a Perfect Square." << endl;
    }

    if (isPerfectCube(number))
    {
        cout << number << " is a Perfect Cube." << endl;
    }
    else
    {
        cout << number << " is NOT a Perfect Cube." << endl;
    }

    return 0;
}
