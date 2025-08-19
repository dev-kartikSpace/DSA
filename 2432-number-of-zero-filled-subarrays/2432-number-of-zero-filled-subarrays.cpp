class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, count = 0;
        for (int num : nums) {
            count = (num == 0) ? count + 1 : 0;
            ans += count;
        }
        return ans;
    }
};
// class Solution {
// public:
//     long long zeroFilledSubarray(vector<int>& nums) {
//         int n = nums.size();
//         int count = 0;
//         vector<int> subArr;
//         for(int i= 0; i < n; i++){
//             if(nums[i] == 0){
//                 count++;
//                 int j = i+1;
//                 while(nums[j] == 0 && j<n){
//                     count++;
//                     j++;
//                 }
//             }
//         }
//         return count;

//     }
// };