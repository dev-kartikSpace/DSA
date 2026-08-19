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
    void Inorder(TreeNode* node, vector<int> &ans){
        if(!node) return;

        Inorder(node->left, ans);
        ans.push_back(node->val);
        Inorder(node->right, ans);

    }
    bool findTarget(TreeNode* root, int k) {
        //i will store it in an array then find if i + j == k
        vector<int> ans;
        
        Inorder(root, ans);

        for(int i = 0; i< ans.size(); i++){
            for(int j = i+1; j<ans.size(); j++){
                if( k == ans[i] + ans[j]) return true;
            }
        }
        return false;
    }
};