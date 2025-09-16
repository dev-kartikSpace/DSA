#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st; // use long long for safety
        
        for (int num : nums) {
            st.push_back(num);
            while (st.size() > 1) {
                long long a = st.back();
                long long b = st[st.size() - 2];
                long long g = gcd(a, b);
                
                if (g == 1) break;
                
                long long lcm = a / g * b; 
                st.pop_back();
                st.back() = lcm;
            }
        }
    
        vector<int> ans(st.begin(), st.end());
        return ans;
    }
};
