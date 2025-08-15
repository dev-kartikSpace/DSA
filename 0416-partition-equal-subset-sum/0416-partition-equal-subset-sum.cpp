class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        
        if (totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        int n = nums.size();
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Empty subset has sum 0
        
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }
        
        return dp[target];
    }
};


//TOP - BOTTOM Approch
// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {
//         int total = 0;
//         for (int num : nums) {
//             total += num;
//         }

//         if (total % 2 != 0)
//             return false;
//         int target = total / 2;
//         int n = nums.size();

//         vector<vector<int>> dp(n, vector<int>(target + 1, -1));
//         return solve(0, target, nums, dp);
//     }
//     bool solve(int i, int target, vector<int>& nums, vector<vector<int>> &dp) {
//         if (target == 0)
//             return true;
//         if (i >= nums.size() || target < 0)
//             return false;

//         if (dp[i][target] != -1)
//             return dp[i][target];

//         int include = solve(i + 1, target - nums[i], nums, dp);
//         int exclude = solve(i + 1, target, nums, dp);

//         return dp[i][target] = include || exclude;
//     }
// };