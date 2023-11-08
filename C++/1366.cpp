class Solution {
public:
    string rankTeams(vector<string>& votes) {
        // using sort
        string ans;
        int len = votes[0].length();
        vector<vector<int>> cnt(26, vector<int> (len, 0));
        vector<bool> appear(26, false);
        for(char c: votes[0]){
            appear[c - 'A'] = true;
        }
        for(string& vote: votes){
            for(int i = 0; i < len; i++){
                cnt[vote[i] - 'A'][i]++;
            }
        }
        for(int i = 0; i < cnt.size(); i++){
            cnt[i].push_back(-i); // append the char at the end so we can compare char alphabetically if they are tied
        }
        sort(cnt.begin(), cnt.end());
        for(int i = cnt.size() - 1; i >= 0; i--){
            char c = 'A' - cnt[i].back();
            if(appear[c - 'A'])
                ans += c;
        }
        return ans;
    }
};