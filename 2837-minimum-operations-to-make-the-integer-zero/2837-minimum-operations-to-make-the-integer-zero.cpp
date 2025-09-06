class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t = 0;
        while(true){
            long long val = (long long) num1 - (long long)t * num2;

            if(val<0) return -1;
            if(__builtin_popcountll(val) <= t && t<= val){
                return t;
            }

            t++;
        }
    }
};

//class Solution {
// public:
//     int makeTheIntegerZero(int num1, int num2) {
//         int temp = INT_MAX;
//         int count = 0;
//         for(int i=1; i<=60; i++){
//             int remain = abs(num1 - (1 << i + num2));
//             if(remain < temp && num1 !=0){
//                 count++;
//                 temp = min(temp, remain);
//                 num1 = remain;
//             }
//             else if(num1 == 0){
//                 return -1;
//             }
//         }
//         return true;
//     }
// };