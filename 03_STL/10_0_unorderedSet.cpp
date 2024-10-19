#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    // Create an unordered_set of integers
    unordered_set<int> mySet;

    // Insert elements into the unordered_set
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(20); // Ignored because 20 is already present

    // Print the elements of the unordered_set
    cout << "Elements of the unordered_set: ";
    for (const auto &elem : mySet)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Check the size of the unordered_set
    cout << "Size of the unordered_set: " << mySet.size() << endl;

    // Erase an element from the unordered_set
    mySet.erase(20);

    // Print the elements of the unordered_set after erasing
    cout << "Elements of the unordered_set after erasing 20: ";
    for (const auto &elem : mySet)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Check if an element is present in the unordered_set
    if (mySet.count(20) > 0)
    {
        cout << "Element 20 is present in the unordered_set." << endl;
    }
    else
    {
        cout << "Element 20 is not present in the unordered_set." << endl;
    }

    return 0;
}
