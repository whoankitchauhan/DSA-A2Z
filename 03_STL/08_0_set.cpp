#include <iostream>
#include <set>

using namespace std;

int main()
{
    // Create a set of integers
    set<int> mySet;

    // Insert elements into the set
    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(20); // Ignored because 20 is already present

    // Print the elements of the set
    cout << "Elements of the set: ";
    for (const auto &elem : mySet)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Check if an element is present in the set
    if (mySet.count(20) > 0)
    {
        cout << "Element 20 is present in the set." << endl;
    }
    else
    {
        cout << "Element 20 is not present in the set." << endl;
    }

    // Erase an element from the set
    mySet.erase(20);

    // Print the size of the set
    cout << "Size of the set after erasing element: " << mySet.size() << endl;

    // Clear the set
    mySet.clear();

    // Check if the set is empty
    if (mySet.empty())
    {
        cout << "The set is empty after clearing." << endl;
    }

    return 0;
}
