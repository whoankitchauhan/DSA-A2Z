#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // Create a priority queue of integers (default max-heap)
    priority_queue<int> myPriorityQueue;

    // Push elements into the priority queue
    myPriorityQueue.push(30);
    myPriorityQueue.push(10);
    myPriorityQueue.push(20);

    // Print the top element (highest priority) of the priority queue
    cout << "Top element of the priority queue: " << myPriorityQueue.top() << endl;

    // Pop the top element from the priority queue
    myPriorityQueue.pop();
    cout << "Popped the top element from the priority queue." << endl;

    // Push more elements into the priority queue
    myPriorityQueue.push(50);
    myPriorityQueue.push(40);

    // Print the size of the priority queue
    cout << "Size of the priority queue: " << myPriorityQueue.size() << endl;

    // Print the elements of the priority queue
    cout << "Elements of the priority queue: ";
    while (!myPriorityQueue.empty())
    {
        cout << myPriorityQueue.top() << " ";
        myPriorityQueue.pop();
    }
    cout << endl;

    // Check if the priority queue is empty after popping all elements
    if (myPriorityQueue.empty())
    {
        cout << "The priority queue is empty after popping all elements." << endl;
    }

    return 0;
}
