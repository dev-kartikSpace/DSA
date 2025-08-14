class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n== 0) return 0;
        if (n == 1) return nums[0];
        // if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp1(n, -1);
        int money1 =  solve(0, n-2, dp1, nums);

        vector<int> dp2(n, -1);
        int money2 = solve(1, n-1, dp2, nums);

        return max(money1, money2);

    }
    int solve(int i, int end,  vector<int>& dp, vector<int>& nums) {
        if (i > end) return 0;

        if (dp[i] != -1) return dp[i];

        int include =  nums[i] + solve(i + 2, end, dp, nums);
        int exclude = solve(i + 1 ,end, dp , nums);

        return dp[i] = max(include , exclude);
    }
};