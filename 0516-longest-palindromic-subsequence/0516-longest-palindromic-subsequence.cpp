class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int lcs(string &s, int i, int j) {
        if (i > j)
            return 0;
        if (i == j)
            return 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == s[j]) {
            return dp[i][j] =  2 + lcs(s, i + 1, j - 1);
        }
        if (s[i] != s[j]) {
            return dp[i][j] = max(lcs(s, i + 1, j), lcs(s, i, j - 1));
        }
        return dp[i][j];
    }
    int longestPalindromeSubseq(string s) {
        n = s.length();
        dp.assign(n, vector<int>(n, -1));
        return lcs(s, 0 , n-1);
    }
};