class Solution {
private:
    class Trie{
    public:
        bool isWord;
        vector<Trie*> child;
        Trie(bool isWord = false){
            this->isWord = isWord;
            this->child = vector<Trie*> (26, NULL);
        }
    };
public:
    void dfs(Trie* root, string& cur, string& ans){
        if(cur.length() > ans.length())
            ans = cur;
        int size = root->child.size();
        for(int i = 0; i < size; i++){
            if(root->child[i] && root->child[i]->isWord){
                cur += ('a' + i);
                dfs(root->child[i], cur, ans);
                cur.pop_back();
            }
        }
        return;
    }
    string longestWord(vector<string>& words) {
        int n = words.size();
        string ans = "", cur = "";
        Trie *root = new Trie();
        for(string& word: words){
            Trie *cur = root;
            for(char c: word){
                if(!cur->child[c - 'a'])
                    cur->child[c - 'a'] = new Trie();
                cur = cur->child[c - 'a'];
            }
            cur->isWord = true;
        }
        dfs(root, cur, ans);
        return ans;
    }
};