class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        if(n ==0) return 0;
        if(n==1) return nums[0];

        return solve(0, dp, nums);
    }
    int solve(int i, vector<int>& dp, vector<int>& nums) {
        if (i >= nums.size())
            return 0;

        if (dp[i] != -1) return dp[i];

        int include = nums[i] + solve(i + 2, dp, nums);
        int exclude = solve(i + 1, dp, nums);

        return dp[i] = max(include, exclude);
    }
};