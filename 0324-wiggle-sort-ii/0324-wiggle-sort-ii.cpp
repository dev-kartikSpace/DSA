// class Solution {
// public:
//     void wiggleSort(vector<int>& nums) {
//         int n = nums.size();
//         for(int i= 1 ; i<n; i++){
//             if((i % 2 != 0 && nums[i-1] > nums[i]) || (i % 2 == 0 &&  nums[i-1] < nums[i])){
//                 swap(nums[i-1], nums[i]);
//             }
//         }
//     }
// };

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        
        int n = nums.size();
        int mid = (n - 1) / 2;   // end of smaller half
        
        // Place smaller numbers on even indices, larger on odd
        for (int i = 0; i < n; i += 2) {
            nums[i] = sorted[mid - i/2];
        }
        for (int i = 1; i < n; i += 2) {
            nums[i] = sorted[n - 1 - i/2];
        }
    }
};