/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* node = root;
        if (node == nullptr)
            return {};

        vector<int> ans;
        vector<int> leftTraverse(postorderTraversal(node->left));
        ans.insert(ans.end(), leftTraverse.begin(), leftTraverse.end());

        vector<int> rightTraverse(postorderTraversal(node->right));
        ans.insert(ans.end(), rightTraverse.begin(), rightTraverse.end());

        ans.push_back(node->val);

        return ans;
    }
};