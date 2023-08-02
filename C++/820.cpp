class Solution {
private:
    class Trie {
    public:
        vector<Trie*> child;
        Trie(){
            child = vector<Trie*> (26, NULL);
        }    
    };
public:
    void dfs(Trie* root, int cur, int& ans){
        bool leaf = true;
        for(Trie* c: root->child){
            if(c){
                leaf = false;
                dfs(c, cur + 1, ans);
            }
        }
        if(leaf)
            ans += (cur + 1);
        return;
    }
    int minimumLengthEncoding(vector<string>& words) {
        int n = words.size();
        Trie *root = new Trie();
        for(string& word: words){
            int len = word.length();
            Trie *cur = root;
            for(int i = len - 1; i >= 0; i--){
                if(!cur->child[word[i] - 'a'])
                    cur->child[word[i] - 'a'] = new Trie();
                cur = cur->child[word[i] - 'a'];
            }
        }
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
};