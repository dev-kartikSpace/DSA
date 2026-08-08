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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                        int preFirst, int preEnd, int inFirst, int inEnd) {

        if (preFirst > preEnd || inFirst > inEnd)
            return nullptr;

        TreeNode* node = new TreeNode(preorder[preFirst]);
        int idx = inFirst;

        while (idx <= inEnd && inorder[idx] != node->val) {
            idx++;
        }

        int left = idx - inFirst;

        node->left = solve(preorder, inorder, preFirst + 1, preFirst + left,
                           inFirst, idx - 1);
        node->right = solve(preorder, inorder, preFirst + left + 1, preEnd,
                            idx + 1, inEnd);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        return solve(preorder, inorder, 0, n-1, 0, n-1);
    }
};