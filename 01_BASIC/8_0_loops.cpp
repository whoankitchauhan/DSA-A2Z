#include <iostream>
using namespace std;

int main() {
    int sum = 0;

    // for loop
    cout << "Using for loop:" << endl;
    for (int i = 1; i <= 5; ++i) {
        sum += i;
    }
    cout << "Sum: " << sum << endl;

    // Reset sum
    sum = 0;

    // while loop
    cout << "Using while loop:" << endl;
    int j = 1;
    while (j <= 5) {
        sum += j;
        ++j;
    }
    cout << "Sum: " << sum << endl;

    // Reset sum
    sum = 0;

    // do-while loop
    cout << "Using do-while loop:" << endl;
    int k = 1;
    do {
        sum += k;
        ++k;
    } while (k <= 5);
    cout << "Sum: " << sum << endl;

    return 0;
}
