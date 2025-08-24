class Solution {
public:
void solve(int idx, int remaining, vector<int>& candidates, int target, vector<vector<int>> &result, vector<int> &path){
    if(remaining == 0){
        result.push_back(path);
        return;
    }

    for(int i = idx; i< candidates.size(); i++){
        if(i > idx && candidates[i] == candidates[i-1])continue;
        if(candidates[i] > remaining) break;
        
        path.push_back(candidates[i]);
        solve(i+1, remaining-candidates[i], candidates, target, result, path);
        path.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, target, result, path);
        return result;
    }
};