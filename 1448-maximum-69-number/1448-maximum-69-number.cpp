class Solution {
public:
    int maximum69Number(int num) {
        int maxNum = num; 
        for (int i = 10; i <= 10000; i *= 10) {
            int digit = (num % i) / (i / 10);
            if (digit == 6) {
                int y = 3 * (i / 10);
                int newNum = num + y; 
                if (newNum > maxNum) {
                    maxNum = newNum;
                }
            }
        }
        return maxNum;
    }
};