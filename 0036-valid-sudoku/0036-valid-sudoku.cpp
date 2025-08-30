#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9; 
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> count;
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '.') {
                    if (count.find(board[i][j]) != count.end()) {
                        return false; 
                    }
                    count[board[i][j]]++;
                }
            }
        }

        // Check columns
        for (int j = 0; j < n; j++) {
            unordered_map<char, int> count;
            for (int i = 0; i < n; i++) {
                if (board[i][j] != '.') {
                    if (count.find(board[i][j]) != count.end()) {
                        return false; 
                    }
                    count[board[i][j]]++;
                }
            }
        }

        // Check 3x3 sub-boxes
        for (int boxRow = 0; boxRow < 3; boxRow++) {
            for (int boxCol = 0; boxCol < 3; boxCol++) {
                unordered_map<char, int> count;
                for (int i = boxRow * 3; i < boxRow * 3 + 3; i++) {
                    for (int j = boxCol * 3; j < boxCol * 3 + 3; j++) {
                        if (board[i][j] != '.') {
                            if (count.find(board[i][j]) != count.end()) {
                                return false; 
                            }
                            count[board[i][j]]++;
                        }
                    }
                }
            }
        }

        return true; 
    }
};