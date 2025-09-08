class Solution {
public:
    bool checkZero(int x) {
        while (x > 0) {
            if (x % 10 == 0)
                return true;
            else
                x /= 10;
        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;
        for (int i = 1; i < n; i++) {
            int a = n - i;
            int b = i;
            if (!checkZero(a) && !checkZero(b)) {
                res.push_back(a);
                res.push_back(b);
                break;
            }
        }
        return res;
    }
};