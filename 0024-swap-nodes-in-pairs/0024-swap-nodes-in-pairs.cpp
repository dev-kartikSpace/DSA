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
        if(!head) return nullptr;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy; 
        ListNode* current = head;

        while (current && current->next) {
            ListNode* nextNode = current->next;

            current->next = nextNode->next;
            nextNode->next = current;
            prev->next = nextNode;
            prev = current;
            current = current->next;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};