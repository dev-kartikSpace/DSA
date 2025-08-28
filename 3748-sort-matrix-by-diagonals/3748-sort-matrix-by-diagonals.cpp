#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Sort diagonals in the bottom-left triangle (including the main diagonal)
        for (int i = 0; i < n; ++i) {
            vector<int> diagonal;
            int row = i;
            int col = 0;
            while (row < n && col < n) {
                diagonal.push_back(grid[row][col]);
                row++;
                col++;
            }
            // Sort in non-increasing order
            sort(diagonal.rbegin(), diagonal.rend());
            
            row = i;
            col = 0;
            int k = 0;
            while (row < n && col < n) {
                grid[row][col] = diagonal[k++];
                row++;
                col++;
            }
        }
        
        // Sort diagonals in the top-right triangle
        for (int j = 1; j < n; ++j) {
            vector<int> diagonal;
            int row = 0;
            int col = j;
            while (row < n && col < n) {
                diagonal.push_back(grid[row][col]);
                row++;
                col++;
            }
            // Sort in non-decreasing order
            sort(diagonal.begin(), diagonal.end());

            row = 0;
            col = j;
            int k = 0;
            while (row < n && col < n) {
                grid[row][col] = diagonal[k++];
                row++;
                col++;
            }
        }

        return grid;
    }
};