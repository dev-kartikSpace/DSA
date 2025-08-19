class Solution {
public:
    int dfs(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        if(amount == 0) return 1;
        if(idx == coins.size() || amount < 0) return 0;
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int include = dfs(idx, amount - coins[idx], coins, dp);
        int exclude = dfs(idx + 1, amount, coins, dp);
        return dp[idx][amount] = include + exclude;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return dfs(0, amount, coins, dp);
    }
};
