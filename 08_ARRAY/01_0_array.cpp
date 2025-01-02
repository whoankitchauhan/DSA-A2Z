#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    // Declaration and initialization of an array
    int myArray[5] = {1, 2, 3, 4, 5};

    // Accessing elements of the array
    cout << "Elements of the array:" << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << "Element " << i << ": " << myArray[i] << endl;
    }

    // Modifying elements of the array
    myArray[2] = 10;
    cout << "Modified array after changing element at index 2:" << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << "Element " << i << ": " << myArray[i] << endl;
    }

    // Sorting array elements
    sort(myArray, myArray + 5);
    cout << "Sorted array:" << endl;
    for (int i = 0; i < 5; ++i)
    {
        cout << "Element " << i << ": " << myArray[i] << endl;
    }

    // Finding the size of the array
    int sizeOfArray = sizeof(myArray) / sizeof(myArray[0]);
    cout << "Size of the array: " << sizeOfArray << endl;

    // Using array from standard library (C++11 and later)
    array<int, 5> stdArray = {6, 7, 8, 9, 10};
    cout << "Elements of the standard library array:" << endl;
    for (int i = 0; i < stdArray.size(); ++i)
    {
        cout << "Element " << i << ": " << stdArray[i] << endl;
    }

    // Accessing elements using iterators
    cout << "Accessing elements using iterators:" << endl;
    for (auto it = begin(stdArray); it != end(stdArray); ++it)
    {
        cout << *it << endl;
    }

    // Accessing elements using range-based for loop (C++11 and later)
    cout << "Accessing elements using range-based for loop:" << endl;
    for (int element : stdArray)
    {
        cout << element << endl;
    }

    return 0;
}
