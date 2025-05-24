class Solution {
public:
    bool check(string& word, char x){
        for(char c: word){
            if(c == x)
                return true;
        }
        return false;
    }
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n = words.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(check(words[i], x))
                ans.push_back(i);
        }
        return ans;
    }
};