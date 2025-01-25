#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to reverse a linked list
ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr;  // Initialize the previous pointer as nullptr
    ListNode *curr = head;     // Current pointer starts at the head
    ListNode *nextt = nullptr; // Pointer to store the next node

    // Iterate through the list
    while (curr != nullptr)
    {
        nextt = curr->next; // Store the next node
        curr->next = prev;  // Reverse the current node's pointer
        prev = curr;        // Move the prev pointer to the current node
        curr = nextt;       // Move to the next node
    }

    return prev; // Return the new head of the reversed list
}

// Function to check if the linked list is a palindrome
bool isPalindrome(ListNode *head)
{
    // Initialize two pointers: slow and fast
    ListNode *slow = head;
    ListNode *fast = head;

    // Step 1: Find the middle of the list
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // Move slow pointer one step
        fast = fast->next->next; // Move fast pointer two steps
    }

    // Step 2: Reverse the second half of the list
    slow = reverse(slow);

    // Step 3: Compare the first and second halves
    ListNode *temp = head; // Start of the first half
    while (slow != nullptr)
    {                               // Traverse the reversed second half
        if (temp->val != slow->val) // If values don't match, it's not a palindrome
            return false;

        temp = temp->next; // Move to the next node in the first half
        slow = slow->next; // Move to the next node in the reversed second half
    }

    return true; // All nodes matched; it's a palindrome
}

// Function to create a linked list from an array
ListNode *createList(int arr[], int n)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *temp = head;
    for (int i = 1; i < n; i++)
    {
        temp->next = new ListNode(arr[i]);
        temp = temp->next;
    }
    return head;
}

// Function to print a linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create linked list
    ListNode *head = createList(arr, n);

    // Check if it's a palindrome
    if (isPalindrome(head))
    {
        cout << "The linked list is a palindrome." << endl;
    }
    else
    {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}
