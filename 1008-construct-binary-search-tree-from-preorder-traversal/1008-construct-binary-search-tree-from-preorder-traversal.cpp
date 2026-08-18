class Solution {
public:
    TreeNode* Solve(vector<int>& preorder, int &idx, int upperBound){
        if(idx == preorder.size() || preorder[idx] > upperBound ) return nullptr;
        TreeNode* root = new TreeNode(preorder[idx++]);
        root->left = Solve(preorder, idx, root->val);
        root->right = Solve(preorder, idx, upperBound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx = 0;
        return Solve(preorder, idx, INT_MAX);
    }
};