#include <iostream>
#include <list>

using namespace std;

int main()
{
    // Creating a list of integers
    list<int> myList;

    // Adding elements to the list
    myList.push_back(10);
    myList.push_front(5); // Add 5 to the front of the list
    myList.push_back(20);

    // Inserting elements at specific positions
    auto it = ++myList.begin(); // Iterator pointing to the second element
    myList.insert(it, 15);      // Insert 15 after the second element

    // Displaying the elements of the list
    cout << "Elements of the list: ";
    for (const auto &elem : myList)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Accessing elements by index (Not supported in lists)
    // cout << "Element at index 2: " << myList[2] << endl; // Error: operator[] not supported

    // Accessing elements using iterators
    cout << "Elements of the list using iterators: ";
    for (auto it = myList.begin(); it != myList.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Removing elements from the list
    myList.pop_front(); // Remove the first element
    myList.pop_back();  // Remove the last element

    // Removing a specific element from the list
    it = ++myList.begin(); // Iterator pointing to the second element
    myList.erase(it);      // Erase the second element

    // Displaying the modified list
    cout << "Modified list: ";
    for (const auto &elem : myList)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Checking if the list is empty
    if (myList.empty())
    {
        cout << "The list is empty." << endl;
    }
    else
    {
        cout << "The list is not empty." << endl;
        cout << "Size of the list: " << myList.size() << endl;
    }

    // Clearing the list
    myList.clear();

    // Checking if the list is empty after clearing
    if (myList.empty())
    {
        cout << "The list is empty after clearing." << endl;
    }

    return 0;
}
