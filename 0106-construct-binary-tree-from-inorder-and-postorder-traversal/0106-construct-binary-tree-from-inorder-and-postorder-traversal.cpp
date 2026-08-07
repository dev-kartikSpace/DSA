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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int posStart, int posEnd){

        if(inStart > inEnd) return NULL;
        TreeNode* node = new TreeNode(postorder[posEnd]);

        int i = inStart;

        for(; i<inEnd; i++ ){
            if(inorder[i] == node->val) break;
        }

        int leftSize = i - inStart;
        int rightSide = inEnd - i;

        node->left = solve(inorder, postorder, inStart, i-1, posStart, posStart+leftSize - 1);
        node->right = solve(inorder, postorder, i+1, inEnd, posEnd - rightSide, posEnd-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int inStart = 0;
        int inEnd = n-1;
        int posStart=0;
        int posEnd = n-1;

        return solve(inorder, postorder, inStart, inEnd, posStart, posEnd);
    }
};