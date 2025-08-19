class Solution {
public:
    int solve(int idx, vector<int> &nums, int target, int total, vector<vector<int>> &dp, int sum) {
        if (idx == nums.size()) {
            return total == target ? 1 : 0;
        }
        if (dp[idx][total + sum] != -1)
            return dp[idx][total + sum];
        
        int add = solve(idx + 1, nums, target, total + nums[idx], dp, sum);
        int minus = solve(idx + 1, nums, target, total - nums[idx], dp, sum);

        return dp[idx][total + sum] = add + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for (int x : nums) sum += x;
        // The possible range of total is [-sum...sum]
        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, -1));
        return solve(0, nums, target, 0, dp, sum);
    }
};
