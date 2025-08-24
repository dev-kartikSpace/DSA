class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0, zeros = 0, res = 0;
        for(int right = 0; right< nums.size(); right++){
            if(nums[right] == 0) zeros++;

            while(zeros > 1){
                if(nums[left] == 0) zeros--;
                left++;
            }

            res = max(res , right- left);
        }
        return res;
    }
};




// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//         int maxLen = 0;
//         solve(nums, 0, 0, 0, maxLen);
//         return maxLen == nums.size() ? maxLen - 1 : maxLen;
//     }

// private:
//     void solve(vector<int>& nums, int idx, int zeros, int ones, int& maxLen) {
//         if (idx >= nums.size()) {
//             maxLen = max(maxLen, ones);
//             return;
//         }

//         if (nums[idx] == 1) {
//             solve(nums, idx + 1, zeros, ones + 1, maxLen);
//         } else if (zeros == 0) {
//             solve(nums, idx + 1, zeros + 1, ones, maxLen);
//         }

//         if (zeros == 0) {
//             solve(nums, idx + 1, 0, 0, maxLen);
//         }

//         maxLen = max(maxLen, ones);
//     }
// };