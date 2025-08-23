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
    vector<TreeNode*> allPossibleFBT(int n) {
        // FBTs can only have an odd number of nodes
        if (n % 2 == 0 || n == 0) {
            return {};
        }
        // Memoization cache to store results for each n
        unordered_map<int, vector<TreeNode*>> memo;
        return solve(n, memo);
    }
    
    vector<TreeNode*> solve(int n, unordered_map<int, vector<TreeNode*>>& memo) {
        // If result for n is already computed, return it
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        
        vector<TreeNode*> result;
        // Base case: 1 node (leaf node)
        if (n == 1) {
            result.push_back(new TreeNode(0));
            return result;
        }
        
        // Try all possible ways to split n-1 nodes into left and right subtrees
        for (int i = 1; i < n; i += 2) { // Left subtree must have odd nodes
            int leftNodes = i;
            int rightNodes = n - 1 - i; // Remaining nodes for right subtree
            if (rightNodes < 0) continue; // Skip invalid cases
            
            // Recursively generate left and right subtrees
            vector<TreeNode*> leftTrees = solve(leftNodes, memo);
            vector<TreeNode*> rightTrees = solve(rightNodes, memo);
            
            // Combine each left and right subtree
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(0);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }
        
        // Cache the result for n
        memo[n] = result;
        return result;
    }
};