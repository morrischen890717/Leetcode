class Trie {
public:
    int id; // stands for the index in dictionary
    vector<Trie*> child;
    Trie(){
        id = -1; // if id != -1, then it is a root in dictionary (index = id)
        child = vector<Trie*> (26, NULL);
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // create Trie
        int n = dictionary.size();
        Trie *root = new Trie();
        for(int i = 0; i < n; i++){
            Trie *cur = root;
            for(char c: dictionary[i]){
                if(!cur->child[c - 'a'])
                    cur->child[c - 'a'] = new Trie();
                cur = cur->child[c - 'a'];
            }
            cur->id = i;
        }

        // split sentence
        vector<string> words;
        int len = sentence.length();
        char *s1 = new char[len + 1];  // char array
        strcpy(s1, sentence.c_str()); // convert sentence into char array so that strtok could be used
        const char* d = " ";
        char *p;
        p = strtok(s1, d);
        while (p != NULL) {
            words.push_back(p);
            p = strtok(NULL, d);		   
        }


        string ans = "";
        for(int i = 0; i < words.size(); i++){
            if(i != 0)
                ans += " ";
            Trie *cur = root;
            bool replace = false;
            for(char c: words[i]){
                if(cur->id != -1){
                    replace = true;
                    break;
                }
                if(!cur->child[c - 'a'])
                    break;
                cur = cur->child[c - 'a'];
            }
            ans += (replace ? dictionary[cur->id] : words[i]);
        }
        return ans;
    }
};