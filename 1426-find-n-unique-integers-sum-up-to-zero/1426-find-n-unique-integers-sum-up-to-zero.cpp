class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        int pairs = n / 2;
        for(int i=1; i<=pairs; ++i){
            result.push_back(i);
            result.push_back(-i);
        }
        if (n % 2 == 1) {
            result.push_back(0);
        }
        return result;
    }
};