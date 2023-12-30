class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        vector<int> cnt(26, 0);
        for(string& word: words){
            for(char& c: word){
                cnt[c - 'a']++;
            }
        }
        for(int i = 0; i < cnt.size(); i++){
            if(cnt[i] % n)
                return false;
        }
        return true;
    }
};