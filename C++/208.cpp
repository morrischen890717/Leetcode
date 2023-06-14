class TrieNode {
    public:
        bool isWord;
        vector<TrieNode*> child;
        TrieNode(){
            isWord = false;
            child = vector<TrieNode*> (26, NULL);
        }
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *cur = root;
        for(char c: word){
            int i = c - 'a';
            if(!cur->child[i])
                cur->child[i] = new TrieNode();
            cur = cur->child[i];
        }
        cur->isWord = true;
        return;
    }
    
    bool search(string word, bool prefix = false) {
        TrieNode *cur = root;
        for(char c: word){
            int i = c - 'a';
            if(!cur->child[i])
                return false;
            cur = cur->child[i];
        }
        return (prefix ? true : cur->isWord);
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */