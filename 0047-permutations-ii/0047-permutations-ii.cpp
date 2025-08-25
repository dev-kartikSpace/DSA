class Solution {
public:
void solve(vector<int>& nums, vector<int> &path, vector<vector<int>> &result, vector<bool>& used){
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
    for(int i = 0; i<nums.size(); i++){
        if(used[i]) continue; 

        if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

        used[i] = true;
        path.push_back(nums[i]);
        solve(nums, path, result, used);
        path.pop_back();
        used[i] = false;
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>path;
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size() , false);
        solve(nums, path, result, used);
        return result;
    }
};