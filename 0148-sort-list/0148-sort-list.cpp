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
// class Solution {
// public:
//     merge {ListNode* left, ListNode* right}{

//         while(left -> next != nullptr && right -> next !+ nullptr){
//             if(left->val > right->val){
//                 if(right-next -> val < right->val){

//                 }
//             }
//         }
//     }
//     ListNode* sortList(ListNode* head) {
//         if (head == nullptr || head->next == nullptr)
//             return head;
//         ListNode* slow = head;
//         ListNode* fast = head->next;
//         while (fast != nullptr && fast->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         ListNode* second = slow->next;
//         slow->next = nullptr;

//         ListNode* left = sortList(head);
//         ListNode* right = sortList(second);

//         return merge(left, right);
//     }
// };

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> nigga;
        ListNode* temp = head;
        while(temp!=nullptr){
            nigga.push_back(temp->val);
            temp = temp->next;
        }
        sort(nigga.begin(),nigga.end());
        temp=head;
        for(int i=0;i<nigga.size();i++){
            temp->val = nigga[i];
            temp=temp->next;
        }
        return head;
    }
};