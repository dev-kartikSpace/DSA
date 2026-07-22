class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++){
            if((i % 2 == 0 && nums[i] % 2 == 0) || (i%2 != 0 && nums[i] % 2 != 0) )continue;

            if(i%2 == 0 && nums[i] %2 != 0){
                int right = i+ 1;
                while(right < nums.size()){
                    if(nums[right] %2  == 0){
                        swap(nums[i], nums[right]);
                        break;
                    }
                    right ++;
                }
            }

            if(i%2 != 0 && nums[i] %2 == 0){
                int right = i+ 1;
                while(right < nums.size()){
                    if(nums[right] %2 != 0 ){
                        swap(nums[i], nums[right]);
                        break;
                    }
                    right ++;
                }
            }


        }
        return nums;
    }
};