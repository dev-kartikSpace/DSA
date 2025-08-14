class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lenS = s.size();
        int index = 0;
        for(int i = 0 ; i < t.size() & index < lenS ; i++){
            if(s[index] == t[i]){
                index++;
            }
        }
        return index == lenS;
    }
};