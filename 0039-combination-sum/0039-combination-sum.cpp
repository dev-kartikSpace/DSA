class Solution {
public:
    int n;
    void solve(vector<int>& candidates, int target, int start, vector<int>& path,
               vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        if (target < 0)
            return;

        for (int i = start; i < n; i++) {
            path.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i, path, result);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<vector<int>> result;
        vector<int> path;
        solve(candidates, target, 0, path, result);
        return result;
    }
};