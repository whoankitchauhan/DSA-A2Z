#include <iostream>
#include <queue>

using namespace std;

int main()
{
    // Create a priority queue of integers (min-heap)
    priority_queue<int, vector<int>, greater<int>> minPriorityQueue;

    // Push elements into the priority queue
    minPriorityQueue.push(30);
    minPriorityQueue.push(10);
    minPriorityQueue.push(20);

    // Print the top element (minimum priority) of the priority queue
    cout << "Top element of the priority queue: " << minPriorityQueue.top() << endl;

    // Pop the top element from the priority queue
    minPriorityQueue.pop();
    cout << "Popped the top element from the priority queue." << endl;

    // Push more elements into the priority queue
    minPriorityQueue.push(50);
    minPriorityQueue.push(40);

    // Print the size of the priority queue
    cout << "Size of the priority queue: " << minPriorityQueue.size() << endl;

    // Print the elements of the priority queue
    cout << "Elements of the priority queue: ";
    while (!minPriorityQueue.empty())
    {
        cout << minPriorityQueue.top() << " ";
        minPriorityQueue.pop();
    }
    cout << endl;

    // Check if the priority queue is empty after popping all elements
    if (minPriorityQueue.empty())
    {
        cout << "The priority queue is empty after popping all elements." << endl;
    }

    return 0;
}
