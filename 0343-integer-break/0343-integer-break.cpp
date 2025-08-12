class Solution {
public:
    int integerBreak(int n) {
        // dp[i] represents the maximum product for integer i
        vector<int> dp(n + 1, 0);
        
        // Base case
        dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            int maxProd = 0;
            
            // Break i into j and i-j, and check products
            for (int j = 1; j < i; j++) {
                // Either don't break the second part (i-j) further or break it using dp
                int prod = j * max(i - j, dp[i - j]);
                maxProd = max(maxProd, prod);
            }
            
            dp[i] = maxProd;
        }
        
        return dp[n];
    }
};
