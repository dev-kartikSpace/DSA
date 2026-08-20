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
    bool findPath(TreeNode* root, int& target, string& path) {
        if (root == nullptr)
            return false;

        if (root->val == target)
            return true;

        path.push_back('L');
        if (findPath(root->left, target, path))
            return true;

        path.pop_back();

        path.push_back('R');
        if (findPath(root->right, target, path) == true)
            return true;

        path.pop_back();
        
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {

        string rootToSource = "";
        string rootToDest = "";

        findPath(root, startValue, rootToSource);
        findPath(root, destValue, rootToDest);

        string ans = "";
        int l = 0;
        while (l < rootToSource.length() && l < rootToDest.length() &&
               rootToSource[l] == rootToDest[l]) {
            l++;
        }

        for (int i = 0; i < rootToSource.length() - l; i++) {
            ans.push_back('U');
        }

        for (int i = l; i < rootToDest.length(); i++) {
            ans.push_back(rootToDest[i]);
        }

        return ans;
    }
};