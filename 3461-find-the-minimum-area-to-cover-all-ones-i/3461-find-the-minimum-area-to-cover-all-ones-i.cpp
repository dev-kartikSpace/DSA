class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int minRow = m, maxRow = -1, minCol = n, maxCol = -1;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == 1) {
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        if (minRow == m) return 0; 
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};


// class Solution {
// public:
//     int m, n;
//     int solve(vector<vector<int>>& grid, int row, int col, int minRow,
//               int maxCol) {

//         if (row >= m || col >= n)
//             return 0;

//         if (grid[i][j] == 1) {
//             minRow = min(minRow, i);
//             maxRow = max(maxRow, i);
//             minCol = min(minCol, j);
//             maxCol = max(maxCol, j);
//         }
//         int right = solve(grid, row, col + 1, minRow, maxCol);
//         int down = solve(grid, row + 1, col, minRow, maxCol);

//         return minRow * maxCol;
//     }
//     int minimumArea(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         return solve(grid, 0, 0, 0, 0);
//     }
// };