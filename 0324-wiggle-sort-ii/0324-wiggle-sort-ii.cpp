class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        int small = (n-1)/2;
        int large = n-1;

        for(int i=0; i<n; i++){
            if(i%2 == 0){
                nums[i] = temp[small--];
            }
            else{
                nums[i] = temp[large--];
            }
        }
    }
};