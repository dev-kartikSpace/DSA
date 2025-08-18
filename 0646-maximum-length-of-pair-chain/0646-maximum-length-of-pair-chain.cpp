class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int count = 0;
        sort(pairs.begin() , pairs.end() , [](const vector<int>& a , const vector<int>&b){ return a[1] < b[1];
        });
        int currEnd = INT_MIN;
        for (const auto& pair : pairs) {
            if (pair[0] > currEnd) {
                count++;
                currEnd = pair[1];
            }
        }
        return count;
    }
};