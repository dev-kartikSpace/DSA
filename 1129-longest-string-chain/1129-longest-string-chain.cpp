class Solution {
public:
    unordered_set<string> st;
    unordered_map<string,int> dp;
    int bfs(string &s){
        int n = s.size();
        if (n == 1) {
            return 1;
        }
        if (dp.count(s))
            return dp[s];
        int ans = 1;
        for (int i = 0; i<n; i++) {
            string curr = s.substr(0, i) + s.substr(i + 1);
            if(st.count(curr))
                ans = max(ans,1 + bfs(curr));
        }
        return dp[s] = ans;
    }
    int longestStrChain(vector<string>& words) {
        for (auto i : words) {
            st.insert(i);
        }
        int ans = 1;
        for (auto i : words) {
            ans = max(ans, bfs(i));
        }
        return ans;
    }
};