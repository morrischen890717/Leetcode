class Solution {
public:
    int minDeletions(string s) {
        int ans = 0;
        int len = s.length();
        vector<int> cnt(26, 0);
        int maxCnt = 0;
        for(char c: s){
            cnt[c - 'a']++;
            maxCnt = max(maxCnt, cnt[c - 'a']);
        }
        unordered_map<int, int> m;
        for(int num: cnt){
            m[num]++;
        }
        for(int i = maxCnt; i > 0; i--){
            if(m.count(i) && m[i] > 1){
                ans += (m[i] - 1);
                m[i - 1] += (m[i] - 1);
            }
        }
        return ans;
    }
};