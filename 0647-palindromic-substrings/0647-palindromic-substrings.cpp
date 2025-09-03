class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int count = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    dp[i][j] = true;
                } else if (j == i + 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
                }
                if (dp[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};

// class Solution {
// public:
// int t[1001][1001];
//     int Check(const string& s, int i, int j) {
//         if(i>j) return true;
//         if(t[i][j] != -1) return t[i][j];
//         if(s[i] == s[j]) return t[i][j] = Check(s, i+1, j-1);
//         return t[i][j] = false;
//     }
//     int countSubstrings(string s) {
//         int n = s.length();
//         int count = 0;
//         memset(t, -1, sizeof(t));
//         for(int i=0; i<n; i++){
//             for(int j= i; j<n; j++){
//                 if(Check(s, i, j)){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };