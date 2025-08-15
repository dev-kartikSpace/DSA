class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        // Initialize dp array with the last row of the triangle
        vector<int> dp = triangle.back();
        
        // Iterate from the second-to-last row to the top
        for (int i = triangle.size() - 2; i >= 0; i--) {
            vector<int> new_dp(triangle[i].size());
            for (int j = 0; j < triangle[i].size(); j++) {
                // For each element, choose the minimum of the two possible paths from the row below
                new_dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
            dp = new_dp; // Update dp for the next row
        }
        
        // The top element contains the minimum path sum
        return dp[0];
    }
};