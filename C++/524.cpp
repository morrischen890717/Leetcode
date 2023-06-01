class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        // using two pointers
        int len = s.length();
        string ans = "";
        for(string word: dictionary){
            if(word.length() < ans.length() || (word.length() == ans.length() && word > ans))
                continue;
            int j = 0;
            for(int i = 0; i < len; i++){
                if(s[i] == word[j]){
                    j++;
                    if(j == word.length()){
                        ans = word;
                    }
                }
            }
        }
        return ans;
    }
};