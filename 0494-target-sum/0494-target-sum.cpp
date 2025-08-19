class Solution {
public:
int n;
int solve(int idx, vector<int> &nums, int target, int total){
    if(idx == nums.size())
    {
        return total == target ? 1 : 0;
    }

    int add = solve(idx + 1, nums , target, total + nums[idx]);
    int minus = solve(idx + 1, nums , target, total - nums[idx]);

    return add + minus;

}
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
       return solve(0, nums, target, 0);
    }
};