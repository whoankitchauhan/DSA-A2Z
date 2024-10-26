#include <iostream>
using namespace std;

// Parameterized Approach to calculate the sum of the first N numbers
int sumOfFirstN(int n, int currentSum) {
    if (n == 0) // Base case: when n is 0, return the accumulated sum
        return currentSum;

    // Recursive call, adding n to the current sum
    return sumOfFirstN(n - 1, currentSum + n);
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Calculate the sum of the first N numbers, starting with currentSum as 0
    int result = sumOfFirstN(n, 0);

    cout << "The sum of the first " << n << " numbers is: " << result << endl;

    return 0;
}
