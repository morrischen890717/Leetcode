class Solution {
public:
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    string convert(string& word){
        string s;
        for(char c: word){
            c = tolower(c);
            s += isVowel(c) ? '.' : c;
        }
        return s;
    }
    string convertLower(string& word){
        string s;
        for(char c: word){
            s += tolower(c);
        }
        return s;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        // using unordered_set and unordered_map
        vector<string> ans;
        unordered_set<string> origin;
        unordered_map<string, string> m;
        for(string& word: wordlist){
            string lower = convertLower(word);
            string s = convert(word);
            origin.insert(word);
            if(!m.count(lower))
                m[lower] = word;
            if(!m.count(s))
                m[s] = word;
        }
        for(string& q: queries){
            if(origin.count(q)){
                ans.push_back(q);
                continue;
            }
            string lower = convertLower(q);
            string s = convert(q);
            if(m.count(lower))
                ans.push_back(m[lower]);
            else if(m.count(s))
                ans.push_back(m[s]);
            else
                ans.push_back("");
        }
        return ans;
    }
};