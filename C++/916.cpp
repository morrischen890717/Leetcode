class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> cnt(26, 0);
        for(string& s: words2){
            vector<int> cnt_s(26, 0);
            for(char c: s){
                cnt_s[c - 'a']++;
            }
            for(int i = 0; i < cnt.size(); i++){
                cnt[i] = max(cnt[i], cnt_s[i]);
            }
        }
        for(string& s: words1){
            vector<int> cnt_s(26, 0);
            bool universal = true;
            for(char c: s){
                cnt_s[c - 'a']++;
            }
            for(int i = 0; i < cnt.size(); i++){
                if(cnt_s[i] < cnt[i]){
                    universal = false;
                    break;
                }
            }
            if(universal)
                ans.push_back(s);
        }
        return ans;
    }
};