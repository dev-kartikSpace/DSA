class Solution {
public:
    int numTrees(int n) {
        vector<long long>dp(n+1, -1);
        return solve(n, dp);
    }
    long long solve(int n, vector<long long> &dp){
        if(n<= 1) return 1;
        if(dp[n] != -1) return dp[n];

        long long ways = 0;
        for(int i= 1; i<=n;i++){
            ways += solve(i-1 , dp) * solve(n-i, dp);
        }
        dp[n] = ways;
        return ways;

    }
};


// class Solution {
// public:
//     int numTrees(int n) {
//         vector<long long>dp(n+1 , 0);
//         dp[0]=1;
//         dp[1]=1;
//         for(int i = 2; i<=n; i++){
//             long long ways=0;
//             for(int j = 1; j<=i;j++){
//                 ways += dp[j-1] * dp[i-j];
//             }
//             dp[i] = ways;
//         }
//         return dp[n];
//     }
// };