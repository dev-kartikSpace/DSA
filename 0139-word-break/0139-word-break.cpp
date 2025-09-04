class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

// class Solution {
// public:
//     bool check(const string& temp, const vector<string>& wordDict) {
//         for (const auto& word : wordDict) {
//             if (temp == word) {
//                 return true;
//             }
//         }
//         return false;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int left = 0;
//         int right = left + 1;
//         while (right < s.length()) {
//             string temp = s.substr(left, right - left + 1);
//             if (!check(temp, wordDict))
//                 return false;
//             else {
//                 left = right + 1;
//                 right++;
//             }
//         }
//         return true;
//     }
// };