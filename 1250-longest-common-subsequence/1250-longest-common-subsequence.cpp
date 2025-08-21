class Solution {
public:
    int n1, n2;
    vector<vector<int>> dp;  // memo table

    int solve(string &text1, string &text2, int i, int j) {
        // base case
        if (i == n1 || j == n2) return 0;

        // if already computed
        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]) {
            // store and return
            return dp[i][j] = 1 + solve(text1, text2, i + 1, j + 1);
        } else {
            return dp[i][j] = max(solve(text1, text2, i + 1, j), solve(text1, text2, i, j + 1));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        n1 = text1.length();
        n2 = text2.length();
        dp.assign(n1, vector<int>(n2, -1)); // initialize dp
        return solve(text1, text2, 0, 0);
    }
};
