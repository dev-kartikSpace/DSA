class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int m = nums[0];

        int left = 1, right = 1;

        for(int i = 0; i< n; i++){
            if(left == 0) left = 1;
            if(right == 0) right = 1;

            left *= nums[i];
            right *= nums[n-1-i];
            m = max(m , max(left, right));
        }

        return m;
    }
};