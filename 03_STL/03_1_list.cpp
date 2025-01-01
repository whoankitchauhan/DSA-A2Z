#include <iostream>
#include <list>

using namespace std;

int main()
{
    // Creating a list of integers
    list<int> myList;

    // Adding elements to the front of the list
    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);

    // Adding elements to the front using emplace_front
    myList.emplace_front(5);
    myList.emplace_front(15);

    // Displaying the elements of the list
    cout << "Elements of the list after push_front and emplace_front: ";
    for (const auto &elem : myList)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
