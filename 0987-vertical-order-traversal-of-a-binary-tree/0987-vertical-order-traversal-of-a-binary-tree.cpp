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
    struct nodeInfo {
        int val;
        int row;
        int col;
    };

    void dfs(TreeNode* node, int row, int col, vector<nodeInfo>& record) {
        if (!node)
            return;
        record.push_back({node->val, row, col});
        dfs(node->left, row+1, col-1, record);
        dfs(node->right, row+1, col+1, record);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<nodeInfo> record;
        dfs(root, 0, 0, record);
        sort(record.begin(), record.end(),
             [](const nodeInfo& a, const nodeInfo& b) {
                 if (a.col != b.col)
                     return a.col < b.col; // sort by column

                 if (a.row != b.row)
                     return a.row < b.row; // then by row

                 return a.val < b.val; // finally by value
             });

        int size = record.size(), idx = 0;
        vector<vector<int>> ans;

        while(idx < size){
            vector<int> temp;

            int column = record[idx].col;
            while(idx<size && record[idx].col == column){
                temp.push_back(record[idx].val);
                idx++;
            }
            ans.push_back(temp);
        }

    return ans;
    }
};