class Solution {
public:
    int kadanesMax(vector<int> &nums, int n){
        int maxSum = nums[0];
        int sum = nums[0];

        for(int i  = 1; i < n; i++){
            sum = max(sum + nums[i] , nums[i]);
            maxSum = max(maxSum , sum);
        }
        return maxSum;
    }
    int kadanesMin(vector<int> &nums, int n){
        int sum = nums[0];
        int minSum = nums[0];
        for(int i = 1; i < n; i++){
            sum = min(sum + nums[i] , nums[i]);
            minSum = min(sum , minSum);
        }
        return minSum;
    }
    
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        // total sum :: point 1
        int Sum = accumulate(begin(nums), end(nums), 0);

        // min sum :: kadens => point 2 
        int minSum = kadanesMin(nums, n);

        // max sum ::kadens => point 3
        int maxSum = kadanesMax(nums, n);

        //circular sum => point 4
        int circularSum = Sum - minSum;

        if(maxSum > 0){
            return max(maxSum, circularSum);
        }

        return maxSum;


    }
};