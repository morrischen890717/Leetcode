class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt = 0;
        unordered_set<char> s;
        for(char c: allowed){
            s.insert(c);
        }
        for(string& word: words){
            bool valid = true;
            for(char c: word){
                if(!s.count(c)){
                    valid = false;
                    break;
                }
            }
            if(valid)
                cnt++;
        }
        return cnt;
    }
};