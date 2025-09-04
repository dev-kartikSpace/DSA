class Solution {
public:
    int findClosest(int x, int y, int z) {
        int dist1 = abs(z - x);
        int dist2 = abs(y-z);
        if(dist1 == dist2){
            return 0;
        }
        else if(dist1 < dist2){
            return 1;
        }
        else{
            return 2;
        }
    }
};