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

// Display list
void display(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Insert at beginning
void insertAtBeginning(Node *&head, int val)
{
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Insert at position (1-based index)
void insertAtPosition(Node *&head, int pos, int val)
{
    if (pos == 1)
    {
        insertAtBeginning(head, val);
        return;
    }

    Node *temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; ++i)
    {
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning(Node *&head)
{
    if (head == NULL)
        return;

    Node *temp = head;
    head = head->next;
    delete temp;
}

// Delete from end
void deleteFromEnd(Node *&head)
{
    if (head == NULL)
        return;

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// Delete at position
void deleteAtPosition(Node *&head, int pos)
{
    if (head == NULL)
        return;

    if (pos == 1)
    {
        deleteFromBeginning(head);
        return;
    }

    Node *temp = head;
    for (int i = 1; temp->next != NULL && i < pos - 1; ++i)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
        return;

    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    delete nodeToDelete;
}

// Search element
bool search(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

// Length of list
int length(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// Reverse list
void reverseList(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

// Driver code
int main()
{
    Node *head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtBeginning(head, 5);
    insertAtPosition(head, 3, 15);

    cout << "Linked List: ";
    display(head);

    cout << "Length: " << length(head) << endl;

    cout << "Search 20: " << (search(head, 20) ? "Found" : "Not Found") << endl;

    deleteAtPosition(head, 3);
    cout << "After deletion: ";
    display(head);

    reverseList(head);
    cout << "After reverse: ";
    display(head);

    return 0;
}