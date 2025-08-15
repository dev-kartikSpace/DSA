// class Solution {
// public:
//     bool canPartition(vector<int>& nums) {

//     }
// };

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            total += num;
        }

        if (total % 2 != 0)
            return false;
        int target = total / 2;
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(0, target, nums, dp);
    }
    bool solve(int i, int target, vector<int>& nums, vector<vector<int>> &dp) {
        if (target == 0)
            return true;
        if (i >= nums.size() || target < 0)
            return false;

        if (dp[i][target] != -1)
            return dp[i][target];

        int include = solve(i + 1, target - nums[i], nums, dp);
        int exclude = solve(i + 1, target, nums, dp);

        return dp[i][target] = include || exclude;
    }
};