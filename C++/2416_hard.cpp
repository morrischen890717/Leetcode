class Trie {
public:
    int cnt;
    Trie *child[26];
    Trie(){
        cnt = 0;
        memset(child, NULL, sizeof(child));
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie *root = new Trie();
        for(string& word: words){
            Trie *cur = root;
            for(char& c: word){
                if(!cur->child[c - 'a'])
                    cur->child[c - 'a'] = new Trie();
                cur = cur->child[c - 'a'];
                cur->cnt++;
            }
        }
        vector<int> ans;
        for(string& word: words){
            int res = 0;
            Trie *cur = root;
            for(char& c: word){
                if(cur->child[c - 'a']){
                    cur = cur->child[c - 'a'];
                    res += cur->cnt;
                }
                else
                    break;
            }
            ans.push_back(res);
        }
        return ans;
    }
};