#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<int>> dp; // dp[remainingSum][currentNumber]

    int numberOfWays(int n, int x) {
        int lastPossibleValue = SearchNumber(n, x);
        dp.assign(n + 1, vector<int>(lastPossibleValue + 2, -1));
        return dfs(n, x, 1, lastPossibleValue);
    }

private:
    int SearchNumber(int n, int x) {
        int start = 1, end = n, ans = 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            long long power = 1;
            for (int i = 0; i < x; i++) {
                power *= mid;
                if (power > n) break;
            }
            if (power <= n) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }

    int dfs(int n, int x, int curr, int last) {
        if (n == 0) return 1;
        if (n < 0 || curr > last) return 0;
        if (dp[n][curr] != -1) return dp[n][curr];

        long long power = 1;
        for (int i = 0; i < x; i++) power *= curr;

        int take = 0;
        if (power <= n) {
            take = dfs(n - power, x, curr + 1, last) % mod;
        }
        int skip = dfs(n, x, curr + 1, last) % mod;

        return dp[n][curr] = (take + skip) % mod;
    }
};
