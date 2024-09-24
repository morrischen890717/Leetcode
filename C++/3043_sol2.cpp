class Trie {
public:
    vector<Trie*> child;
    Trie(){
        child = vector<Trie*> (10, NULL);
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie *root = new Trie();
        for(int num: arr1){
            Trie *cur = root;
            vector<int> v;
            while(num){
                v.push_back(num % 10);
                num /= 10;
            }
            for(int i = v.size() - 1; i >= 0; i--){
                if(!cur->child[v[i]])
                    cur->child[v[i]] = new Trie();
                cur = cur->child[v[i]];
            }
        }
        int ans = 0;
        for(int num: arr2){
            Trie *cur = root;
            vector<int> v;
            while(num){
                v.push_back(num % 10);
                num /= 10;
            }
            int len = 0;
            for(int i = v.size() - 1; i >= 0 && cur->child[v[i]]; i--){\
                cur = cur->child[v[i]];
                len++;
            }
            ans = max(ans, len);
        }
        return ans;
    }
};