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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* node = root;
        if (node == nullptr) {
            return {};
        }
        vector<int> ans;
        vector<int> leftTraverse = inorderTraversal(node->left);
        ans.insert(ans.begin(), leftTraverse.begin(), leftTraverse.end());

        ans.push_back(node->val);

        vector<int> rightTraverse = inorderTraversal(node->right);
        ans.insert(ans.end(), rightTraverse.begin(), rightTraverse.end());

        return ans;
    }
};