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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast){
            fast = fast->next->next;
            slow = slow->next;

        }
        ListNode* curr = slow;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* nextNode = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }

        int maxSum = INT_MIN;
        ListNode* left = head;
        ListNode* right = prev;

        while(right) {
            int sum = left->val + right->val;
            maxSum = max(maxSum, sum);
            left = left->next;
            right = right->next;
        }

        return maxSum;

    }
};


// class Solution {
// public:
//     int pairSum(ListNode* head) {
//         if(!head) return 0;

//         ListNode* left = head;

//         int maxSum = INT_MIN;

//         ListNode* end = head;
//         while(end){
//             end = end->next;
//         }

//         while(left != end){
//             ListNode* right = left->next;
//             while(right ->next != end){
//                 right = right->next;
//             }
//             int sum = left->val + right->val;
//             maxSum = max(sum, maxSum);
//             left=left->next;
//             end = right;
//         }
//         return maxSum;
//     }
// };