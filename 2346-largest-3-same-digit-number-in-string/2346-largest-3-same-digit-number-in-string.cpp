class Solution {
public:
    string largestGoodInteger(string num) {
        if (num.size() < 3) return "";

        char bestDigit = 0;  // track largest digit found
        int count = 1;       // current streak counter
        char prev = num[0];

        for (int i = 1; i < num.size(); i++) {
            if (num[i] == prev) {
                count++;
                if (count == 3) { 
                    if (prev > bestDigit) {
                        bestDigit = prev;
                    }
                }
            } else {
                prev = num[i];
                count = 1;
            }
        }

        if (bestDigit == 0) return "";
        return string(3, bestDigit);
    }
};
