class Solution {
private:
    class Trie {
    public:
        bool isWord;
        vector<Trie*> child;
        Trie(){
            isWord = false;
            child = vector<Trie*> (26, NULL);
        }
    };
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        // using Trie and bottom-up DP
        Trie *root = new Trie();
        for(string& word: dictionary){
            Trie *cur = root;
            for(int i = word.length() - 1; i >= 0; i--){
                char c = word[i];
                if(!cur->child[c - 'a'])
                    cur->child[c - 'a'] = new Trie();
                cur = cur->child[c - 'a'];
            }
            cur->isWord = true;
        }
        int len = s.length();
        vector<int> dp(len + 1, INT_MAX); // dp[i + 1] stands for the minimum number of extra characters left from s[0] ~ s[i]
        dp[0] = 0;
        for(int i = 0; i < len; i++){
            dp[i + 1] = dp[i] + 1;
            Trie *cur = root;
            for(int j = i; j >= 0; j--){
                char c = s[j];
                if(!cur->child[c - 'a'])
                    break;
                cur = cur->child[c - 'a'];
                if(cur->isWord)
                    dp[i + 1] = min(dp[i + 1], dp[j]);
            }
        }
        return dp[len];
    }
};