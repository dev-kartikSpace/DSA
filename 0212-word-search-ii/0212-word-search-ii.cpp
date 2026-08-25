class Solution {
public:
    struct trieNode {
        bool isEndOfWord = false;
        trieNode* children[26];
    };
    trieNode* createNode() {
        trieNode* newNode = new trieNode;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        newNode->isEndOfWord = false;
        return newNode;
    }
    trieNode* root;
    void insert(string& word) {
        trieNode* crawl = root;
        for (auto ch : word) {
            int idx = ch - 'a';
            if (crawl->children[idx] == NULL) {
                crawl->children[idx] = createNode();
            }
            crawl = crawl->children[idx];
        }
        crawl->isEndOfWord = true;
    }

    void dfs(vector<vector<char>>& board, trieNode* crawl, int row, int col,
             vector<string>& ans, string& current) {
        // 1. boundry condition
        int m = board.size();
        int n = board[0].size();
        if (row < 0 || col < 0 || row >= m || col >= n)
            return;

        if (board[row][col] == '#')
            return;
        char ch = board[row][col];
        int idx = ch - 'a';
        if (crawl->children[idx] == NULL)
            return;
        crawl = crawl->children[idx];
        current.push_back(ch);
        // if isendofword is true means we found our word and now store that
        // word in ans array
        if (crawl->isEndOfWord) {
            ans.push_back(current);
            crawl->isEndOfWord = false;
        }
        board[row][col] = '#';

        // ways to move
        dfs(board, crawl, row + 1, col, ans, current);
        dfs(board, crawl, row - 1, col, ans, current);
        dfs(board, crawl, row, col + 1, ans, current);
        dfs(board, crawl, row, col - 1, ans, current);

        board[row][col] = ch;
        current.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        root = createNode();
        for (int i = 0; i < words.size(); i++) {
            insert(words[i]);
        }

        vector<string> ans;
        string current = "";

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, root, i, j, ans, current);
            }
        }

        return ans;
    }
};