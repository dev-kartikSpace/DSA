/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right) prev = prev->right;
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};

// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         TreeNode* dummy = new TreeNode(0);
//         dummy->next = head;
//         TreeNode* curr = dummy;
//         void dfs(root, curr)
//         return dummy->next;
//     }
//     void dfs(TreeNode* root , TreeNode* curr){
//         if(!node) return;
//         if(node->left){
//             curr->next = node->left
//             dfs(root->left, curr)
//         } 
//         else if(node->right){
//             curr->next = node->right
//             dfs(root->right, curr)
//         } 
//     }
// };