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
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n == 0 || n % 2 == 0)
            return {};
        return solve(n);
    }
    vector<TreeNode*> solve(int n) {
        vector<TreeNode*> result;
        if (n == 1) {
            result.push_back(new TreeNode(0));
            return result;
        }
        for (int i = 1; i < n; i += 2) {
            int leftNodes = i;
            int rightNodes = n - 1 - i;
            vector<TreeNode*> leftTrees = solve(leftNodes);
            vector<TreeNode*> rightTrees = solve(rightNodes);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};