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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = prev->next;
        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
                ListNode* temp = curr;
                curr = curr->next;
                delete (temp);
            } else {
                prev = curr;
                curr = curr->next;
            }
        }
        return dummy->next;
    }
};