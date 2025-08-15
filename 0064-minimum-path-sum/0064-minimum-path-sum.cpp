class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();        // rows
        int m = grid[0].size();     // columns
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, dp, grid, n, m);
    }

    int solve(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& grid, int n, int m) {
        if (row >= n || col >= m) return 1e9;
        
        if (row == n - 1 && col == m - 1) return grid[row][col];
        
        if (dp[row][col] != -1) return dp[row][col];
        
        int right = grid[row][col] + solve(row, col + 1, dp, grid, n, m);
        int down  = grid[row][col] + solve(row + 1, col, dp, grid, n, m);
        
        return dp[row][col] = min(right, down);
    }
};
