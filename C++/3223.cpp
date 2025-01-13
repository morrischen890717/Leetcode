class Solution {
public:
    int minimumLength(string s) {
        int ans = 0;
        vector<int> cnt(26, 0);
        for(char c: s){
            cnt[c - 'a']++;
        }
        for(int freq: cnt){
            if(freq == 0)
                continue;
            else if(freq % 2)
                ans++;
            else
                ans += 2;
        }
        return ans;
    }
};