class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxRoot = 0;
        int area = 0;
        for (const auto & dim : dimensions) {
            double sqroot =
                sqrt((long long)dim[0] * dim[0] + (long long)dim[1] * dim[1]);
            int tempArea = dim[0] * dim[1];
            if (maxRoot < sqroot || (abs(sqroot - maxRoot) < 1e-9 && tempArea > area)) {
                area = tempArea;
                maxRoot = sqroot;
            }
        }
        return area;
    }
};