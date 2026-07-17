class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>& vis,
             vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        if (i >= m || j >= n)
            return;
        if (board[i][j] == '.')
            return;

        vis[i][j] = true;
        dfs(i, j + 1, vis, board);
        dfs(i + 1, j, vis, board);
    }
    int countBattleships(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && board[i][j] == 'X') {
                    dfs(i, j, vis, board);
                    count++;
                }
            }
        }

        return count;
    }
};
