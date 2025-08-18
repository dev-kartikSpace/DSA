class Solution {
public:
    long long solve(int idx, vector<int>& nums, bool flag, vector<vector<long long>>& dp) {
        if (idx >= nums.size()) {
            return 0;
        }
        if (dp[idx][flag] != -1) return dp[idx][flag];
        long long skip = solve(idx + 1, nums, flag, dp);
        long long val = (flag ? nums[idx] : -nums[idx]);
        long long take = val + solve(idx + 1, nums, !flag, dp);
        return dp[idx][flag] = max(skip, take);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(2, -1));
        return solve(0, nums, true, dp);
    }
};