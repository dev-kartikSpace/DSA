class Solution {
public:
    int maxArea(vector<int>& height) {
        int vol = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int currVol = (right - left) * min(height[left], height[right]);
            vol = max(vol, currVol);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return vol;
    }
};