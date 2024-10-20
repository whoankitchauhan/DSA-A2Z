#include <iostream>
using namespace std;

// Function to count digits of 'n' that divide 'n'
int countDivisibleDigits(int n)
{
    int count = 0;
    int originalNum = n; // Store the original number for later division checks

    while (n != 0)
    {
        int digit = n % 10; // Extract the last digit

        // If the digit is not zero and divides the original number, increment the count
        if (digit != 0 && originalNum % digit == 0)
        {
            count++;
        }

        n = n / 10; // Remove the last digit from the number
    }

    return count;
}

int main()
{

    cout << "Enter the Number : ";
    int num;
    cin >> num;

    cout << "Number of divisible digits in " << num << ": " << countDivisibleDigits(num) << endl;
    return 0;
}
