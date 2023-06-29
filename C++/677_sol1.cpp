struct Trie {
    int sum = 0;
    Trie* child[26] = {};
};

class MapSum {
public:
    Trie *root;
    unordered_map<string, int> m;
    MapSum() {
        root = new Trie();
    }
    
    void insert(string key, int val) {
        int diff = val - m[key]; // because if the key already existed, the original key-value pair will be overridden to the new one.
        m[key] = val;
        Trie *cur = root;
        for(char c: key){
            if(!cur->child[c - 'a'])
                cur->child[c - 'a'] = new Trie();
            cur = cur->child[c - 'a'];
            cur->sum += diff;
        }
        return;
    }
    
    int sum(string prefix) {
        Trie *cur = root;
        for(char c: prefix){
            if(!cur->child[c - 'a']) // prefix does not exist
                return 0;
            cur = cur->child[c - 'a'];
        }
        return cur->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */