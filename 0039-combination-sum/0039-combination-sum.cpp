class Solution {
public:
    int n;
    void solve(vector<int>& candidates, int target, int idx, vector<int>& path,
               vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        if (target < 0 || idx >= n)
            return;
        path.push_back(candidates[idx]);

        solve(candidates, target - candidates[idx], idx, path, ans);
        path.pop_back();

        solve(candidates, target, idx + 1, path, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<vector<int>> ans;
        vector<int> path;
        solve(candidates, target, 0, path, ans);
        return ans;
    }
};