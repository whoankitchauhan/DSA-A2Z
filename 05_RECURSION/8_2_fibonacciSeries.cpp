// Optimized Approach: Dynamic Programming (Memoization)
// To avoid redundant calculations, we can use memoization to store previously calculated values.

#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n, vector<int> &memo) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];

    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main() {
    int n;
    cout << "Enter the position in the Fibonacci sequence: ";
    cin >> n;

    vector<int> memo(n + 1, -1); // Memoization array
    cout << "Fibonacci(" << n << ") = " << fibonacci(n, memo) << endl;
    return 0;
}
