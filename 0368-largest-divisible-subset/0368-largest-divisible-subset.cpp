class Solution {
public:
    vector<int> nums;
    int n;
    vector<vector<int>> dp;   // dp[i][prev+1] → memoization
    vector<vector<int>> path; // to store best subsets

    // Recursive function to return best subset starting at i with prev index
    vector<int> solve(int i, int prev) {
        if (i == n) return {}; // no elements left

        if (dp[i][prev+1] != -1) 
            return path[i*(n+1) + (prev+1)];

        // Option 1: skip nums[i]
        vector<int> notTake = solve(i+1, prev);

        // Option 2: take nums[i] (if divisible with prev)
        vector<int> take;
        if (prev == -1 || nums[i] % nums[prev] == 0) {
            take = solve(i+1, i);
            take.insert(take.begin(), nums[i]); // add current number
        }

        // Choose bigger subset
        vector<int> best = (take.size() > notTake.size()) ? take : notTake;

        // Memoize
        dp[i][prev+1] = best.size();
        path[i*(n+1) + (prev+1)] = best;

        return best;
    }

    vector<int> largestDivisibleSubset(vector<int>& arr) {
        nums = arr;
        sort(nums.begin(), nums.end());
        n = nums.size();
        dp.assign(n, vector<int>(n+1, -1));
        path.assign(n*(n+1), {});

        return solve(0, -1);
    }
};

// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         vector<int> dp(nums.size(), 1), prev(nums.size(), -1);
//         int maxi = 0;
//         for (int i = 1; i < nums.size(); i++) {
//             for (int j = 0; j < i; j++) {
//                 if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
//                     dp[i] = dp[j] + 1;
//                     prev[i] = j;
//                 }
//             }
//             if (dp[i] > dp[maxi]) maxi = i;
//         }
//         vector<int> res;
//         for (int i = maxi; i >= 0; i = prev[i]) {
//             res.push_back(nums[i]);
//         }
//         return res;
//     }
// };