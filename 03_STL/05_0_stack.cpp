#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // Create a stack of integers
    stack<int> myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Print the top element of the stack
    cout << "Top element of the stack: " << myStack.top() << endl;

    // Pop elements from the stack
    myStack.pop();
    cout << "Popped the top element from the stack." << endl;

    // Push more elements onto the stack
    myStack.push(40);
    myStack.push(50);

    // Print the elements of the stack
    cout << "Elements of the stack: ";
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    // Check if the stack is empty
    if (myStack.empty())
    {
        cout << "The stack is empty." << endl;
    }
    else
    {
        cout << "The stack is not empty." << endl;
    }

    // Push more elements onto the stack
    myStack.push(60);
    myStack.push(70);

    // Print the size of the stack
    cout << "Size of the stack: " << myStack.size() << endl;

    // Clear the stack
    myStack = stack<int>(); // Or myStack.clear() in C++11 and later

    // Check if the stack is empty after clearing
    if (myStack.empty())
    {
        cout << "The stack is empty after clearing." << endl;
    }

    return 0;
}
