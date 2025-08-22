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
//     void solve(vector<vector<int>>& grid, int row, int col, 
//                int& minRow, int& minCol, int& maxRow, int& maxCol) {
//         if (row >= m || col >= n) return;

//         if (grid[row][col] == 1) {
//             minRow = min(minRow, row);
//             maxRow = max(maxRow, row);
//             minCol = min(minCol, col);
//             maxCol = max(maxCol, col);
//         }
//         solve(grid, row, col + 1, minRow, minCol, maxRow, maxCol);
//         solve(grid, row + 1, col, minRow, minCol, maxRow, maxCol);
//     }
    
//     int minimumArea(vector<vector<int>>& grid) {
//         m = grid.size();
//         n = grid[0].size();
//         int minRow = m, minCol = n, maxRow = -1, maxCol = -1;
//         solve(grid, 0, 0, minRow, minCol, maxRow, maxCol);
//         if (minRow == m) return 0; 
//         return (maxRow - minRow + 1) * (maxCol - minCol + 1);
//     }
// };
