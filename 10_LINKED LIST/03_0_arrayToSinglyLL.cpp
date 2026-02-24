#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Convert array to singly linked list
Node *arrayToLL(int arr[], int n)
{
    if (n == 0)
        return NULL;

    Node *head = new Node(arr[0]);
    Node *tail = head;

    for (int i = 1; i < n; ++i)
    {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }

    return head;
}

// Display
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = arrayToLL(arr, n);

    display(head);

    return 0;
}