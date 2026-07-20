class Solution {
public:

    void rotate(vector<vector<int>> &nums){
        int n = nums.size();
        for(int i=0; i< n; i++){
            for(int j = i+1; j<n; j++){
                swap(nums[i][j], nums[j][i]);
            }
        }

        for(int i = 0; i<n; i++){
            reverse(nums[i].begin(), nums[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i=0; i< 4; i++){
            if(mat == target) return true;
            rotate(mat);
        }
        return false;
    }
};