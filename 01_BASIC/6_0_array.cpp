#include <iostream>
using namespace std;

int main()
{
    // Declaration and initialization of a normal array with size 2
    int arr[2];
    arr[0] = 1;

    // Taking user input to set the value of the second element
    cout << "Enter a value for arr[1]: ";
    cin >> arr[1];

    // Printing both elements of the array
    cout << "Values in the array: " << arr[0] << " " << arr[1] << endl;

    return 0;
}
