class Solution {
public:
    class Trie {
    public:
        bool isWord;
        vector<Trie*> child;
        Trie(){
            isWord = false;
            child = vector<Trie*> (26, NULL);
        }
    };
    int solve(string& s, int id, vector<int>& dp, Trie *root){
        if(id == s.length())
            return 1;
        if(dp[id] != 0) // solved
            return dp[id];
        Trie *cur = root;
        int tmp = id;
        while(tmp < s.length() && cur->child[s[tmp] - 'a']){
            cur = cur->child[s[tmp] - 'a'];
            tmp++;
            if(cur->isWord && solve(s, tmp, dp, root) == 1)
                return dp[id] = 1;
        }
        return dp[id] = -1;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie *root = new Trie();
        for(string& word: wordDict){
            Trie *cur = root;
            for(char c: word){
                if(!cur->child[c - 'a'])
                    cur->child[c - 'a'] = new Trie();
                cur = cur->child[c - 'a'];
            }
            cur->isWord = true;
        }
        int len = s.length();
        vector<int> dp(len, 0);
        return solve(s, 0, dp, root) == 1;
    }
};