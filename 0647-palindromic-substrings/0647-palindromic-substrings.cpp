class Solution {
public:
    int Check(const string& s) {
        int r = s.length() -1;
        int l = 0;
        while(l<r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;//include individual chars
        for(int i=0; i<n; i++){
            for(int j= i; j<n; j++){
                if(Check(s.substr(i, j-i+1))){
                    count++;
                }
            }
        }
        return count;
    }
};