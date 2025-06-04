class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1)
            return word;
        int len = word.length();
        string ans = "";
        int n = len - numFriends + 1;
        for(int i = 0; i < len; i++){
            ans = max(ans, word.substr(i, n));
        }
        return ans;
    }
};