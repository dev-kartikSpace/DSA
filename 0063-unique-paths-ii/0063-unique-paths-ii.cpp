class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, dp, obstacleGrid, m, n);
    }

    int solve(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& obstacleGrid, int m, int n) {
        if (row >= m || col >= n) return 0;
        if (obstacleGrid[row][col] == 1) return 0;
        if (row == m - 1 && col == n - 1) return 1;
        if (dp[row][col] != -1) return dp[row][col];

        int down = solve(row + 1, col, dp, obstacleGrid, m, n);
        int right = solve(row, col + 1, dp, obstacleGrid, m, n);

        return dp[row][col] = down + right;
    }
};
