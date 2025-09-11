// class Solution {
// public:
//     string sortVowels(string s) {
//         vector<char> vowels;
//         string VowelSet = "aeiouAEIOU";
//         for(int i=0; i<s.length(); i++){
//             char c = s[i];
//             //npos => return found and not found
//             if(VowelSet.find(c) != string::npos){
//                 vowels.push_back(c);
//             }
//         }
//         sort(vowels.begin(), vowels.end());
//         int j= 0;
//         string ans;
//         for(int i=0;i<s.length(); i++){
//             if (VowelSet.find(s[i]) != string::npos){
//                 ans += vowels[j];
//                 j++;
//             }
//             else{
//                 ans += s[i];
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowels;
        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            }
        }

        sort(vowels.begin(), vowels.end());

        int v_index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowels[v_index++];
            }
        }

        return s;
    }

private:
    bool isVowel(char c) {
        return string("AEIOUaeiou").find(c) != string::npos;
    }
};