#include <iostream>
using namespace std;

int main()
{
    // Creating a string
    string a = "Ankit";

    // Getting the length of the string
    int len = a.size();
    cout << "Length of the string: " << len << endl;

    // Accessing and printing a character at index 1
    cout << "Character at index 1: " << a[1] << endl;

    // Modifying the first and last characters
    a[0] = 'T';
    a[len - 1] = 'A';

    // Printing the modified string
    cout << "Modified string: " << a << endl;

    return 0;
}
