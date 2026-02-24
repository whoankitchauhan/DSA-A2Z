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

// Forward display
void displayForward(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Backward display
void displayBackward(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL\n";
}

// Insert at beginning
void insertAtBeginning(Node *&head, int val)
{
    Node *newNode = new Node(val);

    if (head != NULL)
    {
        head->prev = newNode;
        newNode->next = head;
    }

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
    newNode->prev = temp;
}

// Insert at position (1-based)
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
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

// Delete from beginning
void deleteFromBeginning(Node *&head)
{
    if (head == NULL)
        return;

    Node *temp = head;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    delete temp;
}

// Delete from end
void deleteFromEnd(Node *&head)
{
    if (head == NULL)
        return;

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    }
    else
    {
        head = NULL;
    }

    delete temp;
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
    for (int i = 1; temp != NULL && i < pos; ++i)
    {
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    delete temp;
}

// Search
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

// Length
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

// Reverse DLL
void reverseList(Node *&head)
{
    if (head == NULL)
        return;

    Node *temp = NULL;
    Node *current = head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
    {
        head = temp->prev;
    }
}

// Driver
int main()
{
    Node *head = NULL;

    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtBeginning(head, 5);
    insertAtPosition(head, 3, 15);

    cout << "Forward: ";
    displayForward(head);

    cout << "Backward: ";
    displayBackward(head);

    cout << "Length: " << length(head) << endl;

    cout << "Search 20: " << (search(head, 20) ? "Found" : "Not Found") << endl;

    deleteAtPosition(head, 3);
    cout << "After deletion: ";
    displayForward(head);

    reverseList(head);
    cout << "After reverse: ";
    displayForward(head);

    return 0;
}