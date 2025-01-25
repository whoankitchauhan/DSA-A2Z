#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to detect a cycle in the linked list
bool hasCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    // Traverse the list with two pointers
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // Slow moves 1 step
        fast = fast->next->next; // Fast moves 2 steps

        // If slow and fast meet, a cycle exists
        if (slow == fast)
            return true;
    }

    // If fast pointer reaches the end, there is no cycle
    return false;
}

// Function to print the linked list (for demonstration, prints up to a limit to avoid infinite loop)
void printList(ListNode *head)
{
    ListNode *temp = head;
    int limit = 20; // Limit to prevent infinite printing if there's a cycle
    while (temp != nullptr && limit--)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << (limit == -1 ? "... (cycle detected or long list)" : "") << endl;
}

// Main driver code
int main()
{
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print the linked list
    cout << "Linked List: ";
    printList(head);

    // Manually create a cycle for testing (connect the last node to the second node)
    head->next->next->next->next->next = head->next;

    // Check for cycle
    if (hasCycle(head))
    {
        cout << "Cycle detected in the linked list." << endl;
    }
    else
    {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}
