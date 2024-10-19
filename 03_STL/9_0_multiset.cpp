#include <iostream>
#include <set>

using namespace std;

int main()
{
    // Create a multiset of integers
    multiset<int> myMultiset;

    // Insert elements into the multiset
    myMultiset.insert(10);
    myMultiset.insert(20);
    myMultiset.insert(10); // Duplicate element
    myMultiset.insert(30);

    // Print the elements of the multiset
    cout << "Elements of the multiset: ";
    for (const auto &elem : myMultiset)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Check the size of the multiset
    cout << "Size of the multiset: " << myMultiset.size() << endl;

    // Erase all occurrences of an element
    myMultiset.erase(10);

    // Print the elements of the multiset after erasing
    cout << "Elements of the multiset after erasing all occurrences of 10: ";
    for (const auto &elem : myMultiset)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Check if the multiset is empty
    if (myMultiset.empty())
    {
        cout << "The multiset is empty." << endl;
    }
    else
    {
        cout << "The multiset is not empty." << endl;
    }

    // Clear the multiset
    myMultiset.clear();

    // Check if the multiset is empty after clearing
    if (myMultiset.empty())
    {
        cout << "The multiset is empty after clearing." << endl;
    }

    return 0;
}
