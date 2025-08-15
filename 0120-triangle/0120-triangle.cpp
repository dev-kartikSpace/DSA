class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle.back());

        for (int i = triangle.size() - 2; i >= 0; i--) {
            vector<int> new_dp(triangle[i].size());
            for (int j = 0; j < triangle[i].size(); j++) {
                new_dp[j] = triangle[i][j] + min(dp[j] , dp[j+1]);
            }
            dp = new_dp;
        }
        return dp[0];
    }
};