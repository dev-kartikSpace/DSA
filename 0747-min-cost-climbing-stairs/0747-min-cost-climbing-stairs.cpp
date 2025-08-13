class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return min(solve(0, cost, dp) , solve(1, cost, dp));
    }
    int solve(int i, vector<int>& cost , vector<int>& dp) {
        int n = cost.size();
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int oneStep = cost[i] + solve(i + 1, cost, dp);
        int twoStep = cost[i] + solve(i + 2, cost, dp);
       return dp[i] = min(oneStep , twoStep);
    }
};