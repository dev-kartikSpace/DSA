class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right) {
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            } else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        while (left != nullptr) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while (right != nullptr) {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        return merge(left, right);
    }
};

// class Solution {
// public:
//     ListNode* sortList(ListNode* head) {
//         vector<int> nigga;
//         ListNode* temp = head;
//         while(temp!=nullptr){
//             nigga.push_back(temp->val);
//             temp = temp->next;
//         }
//         sort(nigga.begin(),nigga.end());
//         temp=head;
//         for(int i=0;i<nigga.size();i++){
//             temp->val = nigga[i];
//             temp=temp->next;
//         }
//         return head;
//     }
// };