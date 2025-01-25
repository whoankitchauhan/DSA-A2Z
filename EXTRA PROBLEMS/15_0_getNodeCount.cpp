#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct Node
{
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

// Function to get the count of nodes in the linked list
int getCount(Node *head)
{
    Node *ptr = head;
    int count = 0;
    while (ptr != nullptr)
    {
        ptr = ptr->next;
        count++;
    }
    return count;
}

// Driver code to test the getCount function
int main()
{
    // Creating a linked list: 1 -> 2 -> 3 -> 4
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Test case 1: Get the count of nodes in the list
    cout << "Test case 1: Count of nodes = " << getCount(head) << endl; // Expected output: 4

    // Test case 2: An empty linked list
    Node *emptyHead = nullptr;
    cout << "Test case 2: Count of nodes = " << getCount(emptyHead) << endl; // Expected output: 0

    // Test case 3: A single node in the list
    Node *singleNode = new Node(10);
    cout << "Test case 3: Count of nodes = " << getCount(singleNode) << endl; // Expected output: 1

    return 0;
}
