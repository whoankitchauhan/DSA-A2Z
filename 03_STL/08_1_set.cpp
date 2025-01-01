#include <iostream>
#include <set>

using namespace std;

int main()
{
    // Create a set of integers
    set<int> mySet = {10, 20, 30, 40, 50};

    // Check the size of the set
    cout << "Size of the set: " << mySet.size() << endl;

    // Check if the set is empty
    if (mySet.empty())
    {
        cout << "The set is empty." << endl;
    }
    else
    {
        cout << "The set is not empty." << endl;
    }

    // Count the occurrences of an element
    int count_30 = mySet.count(30);
    cout << "Number of occurrences of 30 in the set: " << count_30 << endl;

    // Erase an element from the set
    mySet.erase(30);

    // Print the elements of the set after erasing
    cout << "Elements of the set after erasing 30: ";
    for (const auto &elem : mySet)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Insert more elements into the set
    mySet.insert(60);
    mySet.insert(70);
    mySet.insert(80);

    // Print the elements of the set after insertion
    cout << "Elements of the set after insertion: ";
    for (const auto &elem : mySet)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Erase elements with specific values using iterators
    auto it = mySet.find(40);
    if (it != mySet.end())
    {
        mySet.erase(it);
    }

    // Print the elements of the set after erasing using iterators
    cout << "Elements of the set after erasing 40 using iterators: ";
    for (const auto &elem : mySet)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
