#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // Create a queue of integers
    queue<int> myQueue;

    // Enqueue elements into the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Print the front element of the queue
    cout << "Front element of the queue: " << myQueue.front() << endl;

    // Print the back element of the queue
    cout << "Back element of the queue: " << myQueue.back() << endl;

    // Enqueue more elements into the queue
    myQueue.push(40);
    myQueue.push(50);

    // Print the size of the queue
    cout << "Size of the queue: " << myQueue.size() << endl;

    // Print the elements of the queue
    cout << "Elements of the queue: ";
    while (!myQueue.empty())
    {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;

    // Check if the queue is empty after popping all elements
    if (myQueue.empty())
    {
        cout << "The queue is empty after popping all elements." << endl;
    }

    return 0;
}
