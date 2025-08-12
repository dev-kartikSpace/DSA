class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1); // memoization array
        return solve(0, n, dp);
    }

private:
    int solve(int i, int n, vector<int> &dp) {
        if (i > n) return 0;     // overshoot
        if (i == n) return 1;    // exactly reached top

        if (dp[i] != -1) return dp[i]; // already computed

        int left = solve(i + 1, n, dp);
        int right = solve(i + 2, n, dp);

        return dp[i] = left + right;
    }
};
