class Solution {
public:
    void solve(vector<int>& nums, int idx, vector<vector<int>>& result, vector<int>& path) {
        result.push_back(path);

        for (int i = idx; i < nums.size(); i++) {
            // skip duplicates
            if (i > idx && nums[i] == nums[i-1]) continue;

            path.push_back(nums[i]);
            solve(nums, i + 1, result, path);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // sorting is must
        vector<vector<int>> result;
        vector<int> path;
        solve(nums, 0, result, path);
        return result;
    }
};
