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

    void Inorder(TreeNode* root, int& key, vector<int>& arr) {
        if (!root)
            return;
        Inorder(root->left, key, arr);
        if (root->val != key) {
            arr.push_back(root->val);
        }
        Inorder(root->right, key, arr);
    }

    TreeNode* construct(vector<int> &arr, int l, int h){
        if(l>h) return NULL;
        int mid = l+(h-l)/2;
        TreeNode* node = new TreeNode(arr[mid]);
        node->left = construct(arr, l, mid-1);
        node->right = construct(arr, mid+1, h);
        return node;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int> arr;
        Inorder(root, key, arr);
        // generate a tree with inorder on  arr
        return construct(arr, 0, arr.size()-1);
    }
};