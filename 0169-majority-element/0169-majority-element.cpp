class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxRepCount = 1;
        int majElement = nums[0];

        for(int i = 0; i< nums.size();){
            int count = 1;
            int j = i + 1;
            int currEl = nums[i];
            while(j < nums.size() && nums[i] == nums[j]){
                count ++;
                j++;
            }
            if(count >= maxRepCount ){
                maxRepCount = count;
                majElement = nums[i];
            }
            i = j;
        }
        return majElement;
    }
};