class Solution {
public:
    int n1, n2;
    int solve(string word1, string word2, int i, int j,
              vector<vector<int>> &dp) {

        if (i == n1) return n2 - j;
        if (j == n2) return n1 - i;

        if (dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]){
            return dp[i][j] = solve(word1, word2, i+1, j+1, dp);
        }
        else{
            int insertOp = 1 + solve(word1, word2, i, j+1, dp);
            int deleteOp = 1 + solve(word1, word2, i+1, j, dp);
            int replaceOp = 1+ solve(word1, word2, i+1, j+1, dp);
            return dp[i][j] = min(insertOp, min(deleteOp, replaceOp));
        }

    }
    int minDistance(string word1, string word2) {
        n1 = word1.length();
        n2 = word2.length();
        vector<vector<int>> dp(n1, vector<int>(n2, -1));
        return solve(word1, word2, 0, 0, dp);
    }
};