class Solution {
public:
    int oneDarrayCount(vector<int> &vec){
        int cons = 0;
        int subCount = 0;
        for(int &val : vec){
            if(val == 0){
                cons =0;
            }
            else{
                cons ++;
            }
            subCount += cons;
        }
        return subCount;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int result =0;
        for(int startRow = 0; startRow<m; startRow++){
            vector<int> vec(n , 1);
            for(int endRow = startRow; endRow <m ; endRow++){
                for(int col = 0; col<n; col++){
                    vec[col] = vec[col] & mat[endRow][col];
                }
                result += oneDarrayCount(vec);
            }
        }
        return result;

    }
};

// class Solution {
// public:
//     int m, n;
//     bool rectangle(int row, int col, vector<vector<int>>& mat, int k) {
//         for(int i = row; i< m -k; i++){
//             for(int j = col; j<n - k; j++){
//                 if(mat[row][col] == 0){
//                     return false;
//                 }
//             }
//         }
//         return false;
//     }
//     int solve(int row, int col, vector<vector<int>>& mat) {
//         if (row >= m || col >= n)
//             return 0;
//         int count = 0;
//         int k = 1;
//         if (mat[row][col] == 1) {
//             k ++;
//             for (int i = row, i < m - 1; i++) {
//                 for (int j = col, j < n - 1, j++) {
//                     if(rectangle(row , col, mat, k)){
//                         count ++;
//                         k++;
//                     }
//                 }
//             }
//         }
//         count += solve(row +1, col, mat);
//         count += solve(row +1, col+1, mat);
//         return count;
//     }
//     int numSubmat(vector<vector<int>>& mat) {
//         m = mat.size();
//         n = mat[0].size();
//         return solve(0, 0, mat);
//     }
// };