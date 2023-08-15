class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> s;
        for(string& word: words){
            vector<vector<int>> cnt(2, vector<int> (26, 0));
            for(int i = 0; i < word.length(); i++){
                cnt[i % 2][word[i] - 'a']++;
            }
            string ss;
            for(int i = 0; i < cnt.size(); i++){
                for(int j = 0; j < cnt[0].size(); j++){
                    ss += to_string(cnt[i][j]);
                    ss += ",";
                }
            }
            s.insert(ss);
        }
        return s.size();
    }
};