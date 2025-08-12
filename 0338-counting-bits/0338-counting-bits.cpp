class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = solve(i, dp);
        }
        return dp;
    }
    private:
    int solve(int i, vector<int> &dp) {
        if(dp[i] != -1) return dp[i];
        dp[i] = solve(i >> 1 , dp) + (i & 1);
        return dp[i];
    }
};