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
    ListNode* reverse(int len, ListNode* curr, int k) {
        if (len < k)
            return curr;

        ListNode* start = curr;
        ListNode* prev = nullptr;
        ListNode* next = curr;
        int count = k;

        while (count--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        len -= k;
        ListNode* rest = reverse(len, curr, k);
        start->next = rest;
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* curr = head;
        while (curr) {
            len++;
            curr = curr->next;
        }
        curr = head;
        return reverse(len, head, k);
    }
};