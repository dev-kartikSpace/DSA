class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> dp;
        solve(n, n, "", dp);
        return dp;
        
    }
    void solve(int left, int right, string curr, vector<string> &res) {
        if (left == 0 && right == 0) {
            res.push_back(curr);
            return;
        }

        if(left > 0){
            solve(left - 1, right, curr + "(", res);
        }

        if (right > left) {
            solve(left, right - 1, curr + ")", res);
        }
    }
};