class Solution {
public:
    int numTrees(int n) {
        return solve(n);
    }
    
private:
    int solve(int n) {
        if (n <= 1) return 1;
        
        int total = 0;
        for (int i = 1; i <= n; ++i) {
            total += solve(i - 1) * solve(n - i);
        }
        return total;
    }
};