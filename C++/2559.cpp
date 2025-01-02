class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> ans;
        vector<int> cnt(n + 1, 0);
        unordered_set<char> s = {'a', 'e', 'i', 'o', 'u'};
        for(int i = 0; i < n; i++){
            cnt[i + 1] = cnt[i];
            if(s.count(words[i][0]) && s.count(words[i].back()))
                cnt[i + 1]++;
        }
        for(vector<int>& q: queries){
            ans.push_back(cnt[q[1] + 1] - cnt[q[0]]);
        }
        return ans;
    }
};