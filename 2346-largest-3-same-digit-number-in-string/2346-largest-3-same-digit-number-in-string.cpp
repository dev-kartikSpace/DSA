class Solution {
public:
    string largestGoodInteger(string num) {
        if (num.size() < 3)
            return "";

        char prev = num[0];
        int count = 1;
        char ans = 0;

        for (int i = 1; i < num.size(); i++) {
            char curr = num[i];
            if (prev == curr) {
                count++;
                if (count == 3) {
                    if (prev > ans) {
                        ans = prev;
                    }
                }
            } else {
                prev = curr;
                count = 1;
            }
        }

        if (ans == 0)
            return "";
        return string(3, ans);
    }
};