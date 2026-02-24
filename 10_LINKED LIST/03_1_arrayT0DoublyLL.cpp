#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// Convert array to doubly linked list
Node *arrayToDLL(int arr[], int n)
{
    if (n == 0)
        return NULL;

    Node *head = new Node(arr[0]);
    Node *tail = head;

    for (int i = 1; i < n; ++i)
    {
        Node *newNode = new Node(arr[i]);

        tail->next = newNode;
        newNode->prev = tail;

        tail = newNode;
    }

    return head;
}

// Forward display
void displayForward(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    int arr[] = {5, 15, 25, 35};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = arrayToDLL(arr, n);

    displayForward(head);

    return 0;
}