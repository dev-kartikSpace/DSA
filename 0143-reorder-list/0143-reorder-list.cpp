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
    void reorderList(ListNode* head) {
        if (!head)
            return;

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = second;
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* first = head;
        ListNode* secondHead = prev;

        while (first && secondHead) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = secondHead->next;

            first->next = secondHead;
            secondHead->next = tmp1;

            first = tmp1;
            secondHead = tmp2;
        }
    }
};
