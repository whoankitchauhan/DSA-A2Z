#include <iostream>
using namespace std;

// Function using pass by value
void incrementByValue(int x)
{
    x++;
    cout << "Inside incrementByValue function: x = " << x << endl;
}

// Function using pass by reference
void incrementByReference(int &x)
{
    x++;
    cout << "Inside incrementByReference function: x = " << x << endl;
}

int main()
{
    int num = 5;

    // Pass by value
    cout << "Before calling incrementByValue: num = " << num << endl;
    incrementByValue(num);
    cout << "After calling incrementByValue: num = " << num << endl;
    cout << "----------------------------------------" << endl;

    // Pass by reference
    cout << "Before calling incrementByReference: num = " << num << endl;
    incrementByReference(num);
    cout << "After calling incrementByReference: num = " << num << endl;

    return 0;
}
