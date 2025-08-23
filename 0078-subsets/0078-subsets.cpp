class Solution {
public:
void solve(vector<int>& nums, int idx,vector<vector<int>> &result, vector<int> &path){
    result.push_back(path);

    for(int i = idx;i <nums.size(); i++){
        path.push_back(nums[i]);
        solve(nums, i+1 , result, path);
        path.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        solve(nums, 0, result, path);
        return result;
    }
};