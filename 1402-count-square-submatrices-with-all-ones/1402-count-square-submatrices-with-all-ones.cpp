class Solution {
public:
    int m, n;

    // Check if a square of size k starting at (row, col) is valid (all 1s)
    bool isValidSquare(int row, int col, int k, vector<vector<int>>& matrix) {
        if (row + k > m || col + k > n) return false;
        for (int i = row; i < row + k; i++) {
            for (int j = col; j < col + k; j++) {
                if (matrix[i][j] == 0) return false;
            }
        }
        return true;
    }

    int solve(int row, int col, vector<vector<int>>& matrix) {
        // Base case: out of bounds
        if (row >= m || col >= n) return 0;

        // Count squares starting at (row, col)
        int count = 0;
        if (matrix[row][col] == 1) {
            // Check squares of size 1, 2, ..., up to max possible size
            for (int k = 1; k <= min(m - row, n - col); k++) {
                if (!isValidSquare(row, col, k, matrix)) {
                    break; // No larger square is possible
                }
                count++; // Valid square of size k
            }
        }

        int right = (col + 1 < n) ? solve(row, col + 1, matrix) : 0;
        int down = (col == 0 && row + 1 < m) ? solve(row + 1, 0, matrix) : 0;

        return count + right + down;
    }

    int countSquares(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        if (m == 0 || n == 0) return 0;
        return solve(0, 0, matrix);
    }
};