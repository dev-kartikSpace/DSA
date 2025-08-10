class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());

        while(start< end){
            int mid = start + (end - start) / 2;
            int totalHours = 0;
            
            for(auto pile : piles){
                //ceiling devision 
                totalHours = totalHours + (pile + mid - 1)/ mid;
            }
            if(totalHours <= h){
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return start;
    }
};