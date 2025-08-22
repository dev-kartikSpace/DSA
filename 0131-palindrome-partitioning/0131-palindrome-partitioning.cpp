class Solution {
public:
    int n;
    bool isPalindrome(string &s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]){
                return false;
            }
        }
        return true;
    }
    void backtrack(int idx, string &s, vector<vector<string>> &result, vector<string> &curr){
        if(idx == n){
            result.push_back(curr);
            return;
        }

        for(int i = idx;i <n; i++){
            if(isPalindrome(s, idx, i)){
                curr.push_back(s.substr(idx, i- idx + 1));
                backtrack(i +1, s, result, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        vector<vector<string>> result;
        vector<string> curr;
        backtrack(0, s, result, curr);
        return result;
    }
};