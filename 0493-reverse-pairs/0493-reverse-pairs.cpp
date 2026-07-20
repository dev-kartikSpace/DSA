class Solution {
public:

    void merge(vector<int> &arr, int start, int mid, int end){
        vector<int> temp(end-start + 1);
        int right = mid+ 1;
        int left = start;
        int index = 0;



        while(left <= mid && right <= end){
            if(arr[left]<=arr[right]){
                temp[index] = arr[left];
                index++;
                left ++;
            }
            else{
                temp[index] = arr[right];
                right++;
                index++;
            }
        }

        while(left <= mid){
            temp[index] = arr[left];
            index++;
            left++;
        }

        while (right <= end) {
			temp[index] = arr[right];
			right++;
			index++;
		}

        index = 0;

        while(start<=end){
            arr[start] = temp[index];
            start++;
            index++;
        }
    }
    int countpairs(vector<int> &nums, int start, int mid, int end){
        int cnt = 0;
        int right=mid+1;
        for(int i=start; i<=mid; i++){
            while(right<=end && nums[i] > 2LL * nums[right]){
                right++;
            }
            cnt += right - (mid + 1);
        }
        return cnt;
    }

    int mergeSort(vector<int>& nums, int low, int high){
        int mid = low + (high - low)/2;
        int cnt = 0;
        if(low == high) return 0;

        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums,mid+1, high);
        cnt += countpairs(nums, low, mid, high);

        merge(nums, low, mid, high);
        return cnt;

    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size()-1);
    }
};