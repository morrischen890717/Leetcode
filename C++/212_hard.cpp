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
    Trie* buildTrie(vector<string>& words){
        Trie *root = new Trie();
        int n = words.size();
        for(string& word: words){
            Trie *cur = root;
            for(char c: word){
                if(!cur->child[c - 'a'])
                    cur->child[c - 'a'] = new Trie();
                cur = cur->child[c - 'a'];
            }
            cur->isWord = true;
        }
        return root;
    }
    void solve(Trie* root, vector<vector<char>>& board, int& m, int& n, int i, int j, vector<int>& dirs, string& cur, vector<string>& ans){
        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '.')
            return;
        char c = board[i][j];
        root = root->child[c - 'a'];
        if(root){
            board[i][j] = '.'; // means that this cell was visited
            cur += c;
            if(root->isWord){
                ans.push_back(cur);
                root->isWord = false; // avoid duplicate answer
            }
            for(int k = 0; k < 4; k++){
                solve(root, board, m, n, i + dirs[k], j + dirs[k + 1], dirs, cur, ans);
            }
            cur.pop_back();
            board[i][j] = c;
        }
        return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // using Trie + DFS + Backtrack
        Trie *root = buildTrie(words);
        int m = board.size(), n = board[0].size();
        vector<string> ans;
        vector<int> dirs = {-1, 0, 1, 0, -1};
        string cur = "";
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                Trie *tmp = root;
                solve(tmp, board, m, n, i, j, dirs, cur, ans);
            }
        }
        return ans;
    }
};