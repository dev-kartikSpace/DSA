// class Solution {
// public:
//     vector<vector<int>> dp;
//     int n;
//     int lcs(string s, int i, int j) {
//         if (i > j)
//             return 0;
//         if (i == j)
//             return 1;
//         if (dp[i][j] != -1)
//             return dp[i][j];
//         if (s[i] == s[j]) {
//             return dp[i][j] =  2 + lcs(s, i + 1, j - 1);
//         }
//         if (s[i] != s[j]) {
//             return dp[i][j] = max(lcs(s, i + 1, j), lcs(s, i, j - 1));
//         }
//         return dp[i][j];
//     }
//     int longestPalindromeSubseq(string s) {
//         n = s.length();
//         dp.assign(n + 1, vector<int>(n + 1, -1));
//         return lcs(s, 0 , n-1);
//     }
// };

class Solution {
public:
    int t[1001][1001];
    int LPS(string& s, int i, int j) {
        if(i > j)
            return 0;
        if(i == j)
            return 1;
        
        if(t[i][j] != -1)
            return t[i][j];
        if(s[i] == s[j])
            return t[i][j] = 2 + LPS(s, i+1, j-1);
        else
            return t[i][j] = max(LPS(s, i+1, j), LPS(s, i, j-1));
    }
    
    int longestPalindromeSubseq(string s) {
        int m = s.length();
        memset(t, -1, sizeof(t));
        
        return LPS(s, 0, m-1); //Approach-1
        
    }
};