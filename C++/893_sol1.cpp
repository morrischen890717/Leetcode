class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> s;
        for(string& word: words){
            vector<string> v(2);
            for(int i = 0; i < word.length(); i++){
                v[i % 2] += word[i];
            }
            for(string& ss: v){
                sort(ss.begin(), ss.end());
            }
            s.insert(v[0] + " " + v[1]);
        }
        return s.size();
    }
};