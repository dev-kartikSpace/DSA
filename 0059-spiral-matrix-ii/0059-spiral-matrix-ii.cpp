class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int right  = n-1;
        int left = 0;
        int bottom = n-1;
        int top = 0;

        int count = 1;
        vector<vector<int>> ans(n, vector<int>(n,0));
        while(top <= bottom && left <= right){

            for(int j = left; j <= right; j++){
                ans[top][j] = count;
                count++;
            }
            top ++;

            for(int i = top; i <= bottom; i++){
                ans[i][right] = count;
                count++;
            }
            right--;

            if(top <= bottom){
                for(int j = right; j >= left; j--){
                    ans[bottom][j] = count;
                    count++;
                }
            }

            bottom --;

            for(int i = bottom; i >= top; i--){
                ans[i][left] = count;
                count ++;
            }
            left ++;
        }
        return ans;
    }
};