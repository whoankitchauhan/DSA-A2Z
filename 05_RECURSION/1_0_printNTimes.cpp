#include <bits/stdc++.h>
using namespace std;

void printMessage(int currentCount, int totalCount) {
    if (currentCount > totalCount)
        return;
    
    cout << "Hey" << endl;
    printMessage(currentCount + 1, totalCount);
}

int main() {
    int repeatCount;
    cout << "Enter the number of times to print 'Hey': ";
    cin >> repeatCount;

    printMessage(1, repeatCount);
    return 0;
}
