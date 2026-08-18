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

    void inorder(TreeNode* root, vector<int> &ans){
        if(!root) return;

        //left node right;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    TreeNode* Build(vector<int> &ans, int l, int r){
        if(l>r) return nullptr;
        int mid = l+(r - l)/2;

        TreeNode* root = new TreeNode(ans[mid]);
        root->left = Build(ans, l, mid-1);
        root->right = Build(ans, mid+1, r);

        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return Build(ans, 0, ans.size()-1);

    }
};