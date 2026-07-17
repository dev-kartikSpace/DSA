class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max = INT_MIN;

        if(nums.size() == 1) return nums[0];
        
        for(int i = 0; i< n; i++){
            int prod = nums[i];
            if(prod >= max) max = prod;
            for(int j = i+1; j< n; j++){
                prod = prod * nums[j];
                if(prod > max) max = prod;
            }
            
        }
        return max;
    }
};