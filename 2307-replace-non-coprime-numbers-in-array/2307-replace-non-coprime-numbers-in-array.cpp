class Solution {
public:

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for(int num: nums){
            st.push_back(num);
            while(st.size() > 1){
                int a = st.back();
                int b = st[st.size() - 2];

                int g = gcd(a,b);
                if(g == 1) break;

                long long lcm = a/g * b;
                st.pop_back();
                st.back() = lcm;
            }
        }
        return st;
    }
};