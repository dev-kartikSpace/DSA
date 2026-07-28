class Solution {
public:
    vector<int> getLeftMax(vector<int>& height, int& n){
        vector<int> Lmax(n);
        Lmax[0] = height[0];
        for(int i = 1; i <n; i++){
            Lmax[i] = max(Lmax[i-1], height[i]);
        }
        return Lmax;
    }
    vector<int> getRightMax(vector<int>& height, int& n){
        vector<int> Rmax(n);
        Rmax[n-1] = height[n-1];
        for(int i = n-2; i >=0; i--){
            Rmax[i] = max(Rmax[i+1], height[i]);
        }
        return Rmax;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> Lmax = getLeftMax(height, n);
        vector<int> Rmax = getRightMax(height, n);

        int sum = 0;
        for(int i = 0; i< n; i++){
            int h = min(Lmax[i] , Rmax[i]) - height[i];
            sum += h;
        }

        return sum;
    }
};