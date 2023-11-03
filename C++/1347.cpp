class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> cnt(26, 0);
        int len = s.length();
        for(int i = 0; i < len; i++){
            cnt[s[i] - 'a']--;
            cnt[t[i] - 'a']++;
        }
        int ans = 0;
        for(int i = 0; i < cnt.size(); i++){
            if(cnt[i] > 0)
                ans += cnt[i];
        }
        return ans;
    }
};