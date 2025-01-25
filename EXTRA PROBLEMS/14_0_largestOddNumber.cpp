#include <iostream>
#include <string>
using namespace std;

// Function to find the largest odd-numbered substring
string largestOddNumber(string num)
{
    // Iterate from the last character to the first
    for (int i = num.size() - 1; i >= 0; i--)
    {
        int digit = num[i] - '0'; // Convert character to integer
        if (digit % 2 == 1)
        {                                // Check if the digit is odd
            return num.substr(0, i + 1); // Return substring up to the odd digit
        }
    }
    return ""; // If no odd digit is found, return an empty string
}

int main()
{
    // Test case 1: A number with an odd digit at the end
    string num1 = "23456";
    cout << "Test case 1: " << largestOddNumber(num1) << endl; // Expected: "2345"

    // Test case 2: A number where the last digit is odd
    string num2 = "12345";
    cout << "Test case 2: " << largestOddNumber(num2) << endl; // Expected: "12345"

    // Test case 3: A number with no odd digits
    string num3 = "2468";
    cout << "Test case 3: " << largestOddNumber(num3) << endl; // Expected: ""

    // Test case 4: A single-digit odd number
    string num4 = "7";
    cout << "Test case 4: " << largestOddNumber(num4) << endl; // Expected: "7"

    // Test case 5: A single-digit even number
    string num5 = "8";
    cout << "Test case 5: " << largestOddNumber(num5) << endl; // Expected: ""

    return 0;
}
