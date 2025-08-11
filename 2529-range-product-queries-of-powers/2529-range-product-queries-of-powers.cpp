#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        vector<int> powers;
        for (int i = 0; i < 31; i++) { 
            if (n & (1 << i)) { 
                powers.push_back(1 << i);
            }
        }
        vector<int> ans;
        for (auto& q : queries) {
            int left = q[0];
            int right = q[1];
            long long product = 1; 
            for (int i = left; i <= right; i++) {
                product = (product * powers[i]) % MOD;
            }
            ans.push_back((int)product);
        }
        return ans;
    }
};
