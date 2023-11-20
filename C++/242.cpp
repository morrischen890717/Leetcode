class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> cnt;
        for(char c: s){
            cnt[c]++;
        }
        for(char c: t){
            if(cnt.count(c) == 0)
                return false;
            cnt[c]--;
        }
        for(unordered_map<char, int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            if(it->second != 0)
                return false;
        }
        return true;
    }
};