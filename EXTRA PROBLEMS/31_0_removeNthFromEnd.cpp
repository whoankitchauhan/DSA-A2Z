#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to remove N-th node from end
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *slow = dummy;
    ListNode *fast = dummy;

    // Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; i++)
    {
        fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Skip the node to be deleted
    ListNode *nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete nodeToDelete; // free memory

    return dummy->next;
}

// Helper to create linked list from vector
ListNode *createList(const vector<int> &vals)
{
    if (vals.empty())
        return nullptr;
    ListNode *head = new ListNode(vals[0]);
    ListNode *current = head;
    for (size_t i = 1; i < vals.size(); ++i)
    {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

// Helper to print linked list
void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val;
        if (head->next != nullptr)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// Test driver
int main()
{
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3, 4, 5}, 2},
        {{1}, 1},
        {{1, 2}, 1},
        {{1, 2}, 2},
        {{10, 20, 30, 40, 50, 60}, 4}};

    int testNum = 1;
    for (size_t i = 0; i < testCases.size(); ++i)
    {
        vector<int> vals = testCases[i].first;
        int n = testCases[i].second;

        cout << "Test Case " << testNum++ << ": Remove " << n << "-th node from end" << endl;
        ListNode *head = createList(vals);
        cout << "Original: ";
        printList(head);

        ListNode *updatedHead = removeNthFromEnd(head, n);
        cout << "Updated : ";
        printList(updatedHead);
        cout << "----------------------" << endl;
    }

    return 0;
}
