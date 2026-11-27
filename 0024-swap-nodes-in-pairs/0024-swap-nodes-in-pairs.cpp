/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        // Dummy node makes swapping the head easier
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        // Swap two nodes at a time
        while (prev->next && prev->next->next) {

            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Change links to swap the two nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move ahead for the next pair
            prev = first;
        }

        return dummy.next;
    }
};
