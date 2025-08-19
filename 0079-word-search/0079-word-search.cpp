class Solution {
public:
    int m;
    int n;
    bool solve(int row, int col, int i, vector<vector<char>>& board,
               string word) {

        if (i == word.size())
            return true;

        if (row < 0 || row >= m || col < 0 || col >= n ||
            board[row][col] != word[i])
            return false;

        char temp = board[row][col]; 
        board[row][col] = '#';

        bool found = solve(row, col + 1, i + 1, board, word) ||
                    solve(row + 1, col, i + 1, board, word) ||
                    solve(row, col - 1, i + 1, board, word) ||
                    solve(row - 1, col, i + 1, board, word);
        
        board[row][col] = temp;  
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i = 0 ; i<m ;i++){
            for(int j = 0 ; j < n ; j++){
                if (solve(i, j, 0, board, word))
                    return true;
            }
        }
        return false;
    }
};