#include <iostream>
using namespace std;

// Definition for doubly linked list node
struct Node
{
    int val;
    Node *next;
    Node *prev;
    Node(int x) : val(x), next(nullptr), prev(nullptr) {}
};

// Function to delete a node at position x
Node *deleteNode(Node *head, int x)
{
    // Edge case: If the list is empty
    if (head == nullptr)
        return nullptr;

    // Case 1: Deleting the head node
    if (x == 1)
    {
        Node *temp = head;
        head = head->next; // Move the head pointer to the next node
        if (head != nullptr)
        {
            head->prev = nullptr; // Update the prev pointer of the new head (if it exists)
        }
        delete temp; // Free the memory for the deleted node
        return head; // Return the updated head
    }

    // Traverse to the node at position x
    Node *temp = head;
    for (int i = 1; temp != nullptr && i < x; i++)
    {
        temp = temp->next; // Move to the next node
    }

    // If the node at position x doesn't exist
    if (temp == nullptr)
        return head;

    // Case 2: Deleting the tail node
    if (temp->next == nullptr)
    {
        temp->prev->next = nullptr; // Update the next pointer of the previous node
        delete temp;                // Free the memory for the deleted node
        return head;                // Return the updated head
    }

    // Case 3: Deleting a middle node
    temp->prev->next = temp->next; // Link the previous node to the next node
    temp->next->prev = temp->prev; // Link the next node to the previous node
    delete temp;                   // Free the memory for the deleted node

    return head; // Return the updated head
}

// Function to print the list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main driver code
int main()
{
    // Creating a doubly linked list: 1 <-> 2 <-> 3 <-> 4
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    cout << "Original List: ";
    printList(head);

    // Deleting node at position 2 (Node with value 2)
    head = deleteNode(head, 2);
    cout << "List after deleting node at position 2: ";
    printList(head);

    // Deleting node at position 1 (Head node)
    head = deleteNode(head, 1);
    cout << "List after deleting node at position 1: ";
    printList(head);

    // Deleting node at position 3 (Tail node)
    head = deleteNode(head, 3);
    cout << "List after deleting node at position 3: ";
    printList(head);

    return 0;
}
