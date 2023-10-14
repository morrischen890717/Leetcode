class Solution {
private:
    class Trie {
    public:
        vector<int> ids;
        vector<Trie*> child;
        Trie(){
            child = vector<Trie*> (26, NULL);
        }
    };
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        // using Trie
        vector<vector<string>> ans(searchWord.length());
        int n = products.size();
        sort(products.begin(), products.end());
        Trie *root = new Trie();
        for(int i = 0; i < n; i++){
            string& product = products[i];
            Trie *cur = root;
            for(char c: product){
                if(!cur->child[c - 'a'])
                    cur->child[c - 'a'] = new Trie();
                cur = cur->child[c - 'a'];
                cur->ids.push_back(i);
            }
        }
        for(int i = 0; i < searchWord.length(); i++){
            Trie *cur = root;
            bool empty = false;
            for(int j = 0; j <= i; j++){
                if(cur->child[searchWord[j] - 'a'])
                    cur = cur->child[searchWord[j] - 'a'];
                else{
                    empty = true;
                    break;
                }
            }
            if(!empty){
                for(int id = 0; id < cur->ids.size() && id < 3; id++){
                    ans[i].push_back(products[cur->ids[id]]);
                }
            }
        }
        return ans;
    }
};