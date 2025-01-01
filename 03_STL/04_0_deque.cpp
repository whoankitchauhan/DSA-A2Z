#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // Create a deque of integers
    deque<int> myDeque;

    // Push elements to the back of the deque
    myDeque.push_back(10);
    myDeque.push_back(20);
    myDeque.push_back(30);

    // Push elements to the front of the deque
    myDeque.push_front(5);
    myDeque.push_front(15);

    // Print elements of the deque
    cout << "Elements of the deque: ";
    for (const auto &elem : myDeque)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Access elements using indexing (similar to vectors)
    cout << "Element at index 2: " << myDeque[2] << endl;

    // Pop elements from both ends
    myDeque.pop_front();
    myDeque.pop_back();

    // Print elements after popping
    cout << "Elements of the deque after popping: ";
    for (const auto &elem : myDeque)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Print the front and back elements of the deque
    cout << "Front element: " << myDeque.front() << endl;
    cout << "Back element: " << myDeque.back() << endl;

    return 0;
}
