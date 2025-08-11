class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        vector<int>powers;
        for(int i = 0; i<31; i++){
            if(n & (1<<i)){
                powers.push_back(1<<i);
            }
        }

        vector<int>ans;

        for(auto query : queries){
            int left = query[0];
            int right = query[1];
            long long product = 1;
            for(int i = left ; i <= right ; i++){
                product = (product * powers[i]) % mod;
            }
            ans.push_back(product);
        }
        return ans;
    }
};