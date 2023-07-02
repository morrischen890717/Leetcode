class MagicDictionary {
public:
    vector<vector<string>> dictionary;
    MagicDictionary() {
        dictionary = vector<vector<string>> (101);
    }
    
    void buildDict(vector<string> dictionary) {
        for(string& word: dictionary){
            int len = word.length();
            this->dictionary[len].push_back(word);
        }
        return;
    }
    
    bool search(string searchWord) {
        int len = searchWord.length();
        for(string& s: dictionary[len]){
            if(onlyOneDiff(s, searchWord))
                return true;
        }
        return false;
    }

    bool onlyOneDiff(string& s1, string& s2){
        int len = s1.length();
        int l = 0, r = len - 1;
        while(l < len && s1[l] == s2[l]){
            l++;
        }
        while(r >= 0 && s1[r] == s2[r]){
            r--;
        }
        return l == r;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */