// class Solution {
// public:
//     bool isPalindrome(const string& s, int left, int right) {
//         while (left < right) {
//             if (s[left] != s[right])
//                 return false;
//             ++left;
//             --right;
//         }
//         return true;
//     }
//     string longestPalindrome(string s) {
//         int n = s.size();
//         if (n < 2) return s;

//         int maxLen = 1;
//         int startIdx = 0;

//         for (int i = 0; i < n; ++i) {
//             for (int j = i; j < n; ++j) {
//                 if (isPalindrome(s, i, j) && (j - i + 1) > maxLen) {
//                     maxLen = j - i + 1;
//                     startIdx = i;
//                 }
//             }
//         }
//         return s.substr(startIdx, maxLen);
//     }
    
// };
class Solution {
public:
string checkPali(string s, int ptr1,int ptr2){
        
    while(ptr1>=0 && ptr2<s.size() && s[ptr1]==s[ptr2]){
                ptr2++;
                ptr1--;
            }
            string temp=s.substr(ptr1+1,ptr2-ptr1-1);
           
        return temp;
        }

    string longestPalindrome(string s) {
       string result="";
        int maxi=0;
        
        for(int i=0; i<s.size(); i++){
          int ptr1=i,ptr2=i;
          while(s[ptr1]==s[ptr2]){
            ptr2++;
          }  
        string temp=checkPali(s,ptr1,ptr2-1);
         if(temp.size()>maxi){
                result=temp;
                maxi=temp.size();
            }
       }
       return result;
    }
};