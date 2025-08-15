class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix; // copy

        for (int row = n - 2; row >= 0; --row) {
            for (int col = 0; col < n; ++col) {
                int down = dp[row + 1][col];
                int left = (col > 0) ? dp[row + 1][col - 1] : 1e9;
                int right = (col < n - 1) ? dp[row + 1][col + 1] : 1e9;
                dp[row][col] += min({down, left, right});
            }
        }
        return *min_element(dp[0].begin(),dp[0].end());
    }
};


// TOP TO BOTTOM APPROCH
//  class Solution {
//  public:
//      int minFallingPathSum(vector<vector<int>>& matrix) {
//          int m = matrix.size();
//          int n = matrix[0].size();

//         vector<vector<int>> dp(m , vector<int>(n , -1));
//         int minSum = INT_MAX;

//         for(int i = 0 ; i < n ; i++){
//             int temp = solve(0, i, m, n, dp, matrix);
//             minSum = min(minSum , temp);
//         }
//         return minSum;
//     }

//     int solve(int row , int col, int m, int n,  vector<vector<int>> &dp,
//     vector<vector<int>> &matrix){

//         if(col <0 || col >= n) return 1e9;
//         if( row == m-1) return matrix[row][col];
//         if(dp[row][col] != -1) return dp[row][col];

//         int down = matrix[row][col] +  solve(row + 1 , col, m ,n , dp ,
//         matrix); int BottomRight = matrix[row][col] + solve(row + 1 , col +
//         1, m ,n , dp , matrix); int BottomLeft = matrix[row][col] + solve(row
//         + 1 , col - 1, m ,n , dp , matrix);

//         return dp[row][col] = min({down, BottomRight, BottomLeft});

//     }
// };