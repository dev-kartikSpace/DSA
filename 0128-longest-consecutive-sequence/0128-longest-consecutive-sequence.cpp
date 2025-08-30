class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        unordered_set<int>s;
        int longest=1;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        for(auto it : s){
            if(s.find(it-1)==s.end()){
                int cnt=1;
                int x=it;
                while(s.find(x+1)!=s.end()){
                    cnt++;
                    x++;
                }
                longest=max(longest,cnt);
            }
        }
        return longest;
    }
};