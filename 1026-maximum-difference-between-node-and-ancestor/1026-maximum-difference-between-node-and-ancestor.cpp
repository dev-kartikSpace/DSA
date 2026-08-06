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
    int helper(TreeNode* root, int minValue, int maxValue, int diff) {

        if (!root)
            return diff;

        TreeNode* node = root;

        minValue = min(minValue, root->val);
        maxValue = max(maxValue, root->val);

        int currDiff = maxValue - minValue;

        diff = max(diff, currDiff);
        if(diff < 0) diff *= -1;

        return max(helper(node->left, minValue, maxValue, diff),
                   helper(node->right, minValue, maxValue, diff));


    }
    int maxAncestorDiff(TreeNode* root) {
        TreeNode* node = root;
        int diff = 0;
        return helper(node, root->val, root->val, diff);
    }
};