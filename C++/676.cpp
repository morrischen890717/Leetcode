class MagicDictionary {
private:
    unordered_map<int, vector<string>> m;
public:
    MagicDictionary() {
        
    }
    int charDiff(string& s1, string& s2){
        int cnt = 0, len = s1.length();
        for(int i = 0; i < len; i++){
            if(s1[i] != s2[i])
                cnt++;
        }
        return cnt;
    }
    
    void buildDict(vector<string> dictionary) {
        for(string& word: dictionary){
            int len = word.length();
            m[len].push_back(word);
        }
        return;
    }
    
    bool search(string searchWord) {
        int len = searchWord.length();
        for(string& word: m[len]){
            if(charDiff(word, searchWord) == 1)
                return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */