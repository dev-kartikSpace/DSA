class Solution {
public:
    // I will solve this question with merge sort

    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int j = mid+1;
        int i = low;
        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i]);
                i++;
            } else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]);
            i ++;
        }
        while(j <= high){
            temp.push_back(nums[j]);
            j++;
        }

        for(int k = low; k<= high; k++){
            nums[k] = temp[k-low];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        // base case
        if (low >= high)
            return;
        int mid = low + (high - low) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);

        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};