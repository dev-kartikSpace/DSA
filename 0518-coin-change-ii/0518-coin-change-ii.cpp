class Solution {
public:
    int n;
    int solve(int i, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if(amount == 0) return 1; 
        if(i == coins.size() || amount < 0) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        int take = solve(i, coins, amount - coins[i],dp);
        int skip = solve(i+1, coins, amount,dp);
        return dp[i][amount] = take + skip;
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount + 1, -1));
        return solve(0, coins, amount, dp);
    }
};