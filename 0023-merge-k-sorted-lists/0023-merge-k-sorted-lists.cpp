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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        // Min heap to always get the smallest node
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        // Add the first node of every list
        for (auto node : lists) {
            if (node) {
                pq.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Keep picking the smallest node
        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            // Attach it to our answer list
            tail->next = node;
            tail = tail->next;

            // Add the next node from the same list
            if (node->next) {
                pq.push(node->next);
            }
        }

        tail->next = nullptr;

        return dummy.next;
    }
};
