class Solution {
public:
    int minOperations(string s) {
        int op = 0;
        for(auto & ch:s){
            int Individual_steps = 0;
            if(ch  == 'a') continue;
            else{
                Individual_steps = 'z' - ch + 1;
                op = max(Individual_steps , op);
            }
        }
        return op;
    }
};