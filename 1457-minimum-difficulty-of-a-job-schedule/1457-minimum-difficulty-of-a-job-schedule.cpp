class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int solve(int idx, int day, vector<int>& jobDifficulty, int d) {
        if (day == d) {
            // if (idx >= n) return INT_MAX; 
            int maxD = 0;
            for (int i = idx; i < n; i++) {
                maxD = max(maxD, jobDifficulty[i]);
            }
            return maxD;
        }

        // if (idx > n - (d - day + 1)) return INT_MAX;
        if (dp[idx][day] != -1)
            return dp[idx][day];

        int maxD = 0, ans = INT_MAX;
        for (int i = idx; i <= n - (d - day + 1); i++) {
            maxD = max(maxD, jobDifficulty[i]);
            int next = solve(i + 1, day + 1, jobDifficulty, d);
            if (next != INT_MAX) {
                ans = min(ans, maxD + next);
            }
        }
        return dp[idx][day] = (ans == INT_MAX ? INT_MAX : ans);
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        n = jobDifficulty.size();
        if (n < d) return -1;
        dp.assign(n, vector<int>(d + 1, -1));
        int result = solve(0, 1, jobDifficulty, d);
        return result == INT_MAX ? -1 : result;
    }
};