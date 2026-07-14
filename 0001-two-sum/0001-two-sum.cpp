class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> ans(2);
        for(int i = 0; i< size;){
            for(int j = i+1; j< size;){
                if(target == nums[i] + nums[j]){
                    ans[0] = i;
                    ans[1] = j;
                    return ans ; 
                }
                else{
                    j++;
                }
            }
            i++;
        }
        return ans;
    }
};