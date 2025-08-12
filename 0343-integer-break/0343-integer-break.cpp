class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            int maxProd = 0;
            for (int j = 1; j < i; j++) {
                int prod = j * max(i - j, dp[i - j]);
                maxProd = max(maxProd, prod);
            }
            dp[i] = maxProd;
        }
        return dp[n];
    }
};
