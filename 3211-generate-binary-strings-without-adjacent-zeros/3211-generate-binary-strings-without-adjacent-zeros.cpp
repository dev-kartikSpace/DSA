class Solution {
public:
    void solve(vector<string> &arr, int idx, string curr, int n) {

        // base case
        if (idx == n) {
            arr.push_back(curr);
            return;
        }

        // put 0 and recurse
        if (idx == 0 || curr[idx - 1] != '0') {
            curr[idx] = '0';
            solve(arr, idx + 1, curr, n);
        }

        // put 1 and recurse
        curr[idx] = '1';
        solve(arr, idx + 1, curr, n);
    }
    vector<string> validStrings(int n) {
        vector<string> arr;
        string curr(n, ' ');
        solve(arr, 0, curr, n);
        return arr;
    }
};