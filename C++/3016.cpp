class Solution {
public:
    int minimumPushes(string word) {
        // using sort
        int ans = 0;
        vector<int> cnt(26, 0);
        for(char c: word){
            cnt[c - 'a']++;
        }
        sort(cnt.begin(), cnt.end(), [&](int a, int b){
            return a > b;
        });
        for(int i = 0; i < 26; i++){
            ans += cnt[i] * (1 + i / 8); // (1 + i / 8) stands for the times of pressing the key
        }
        return ans;
    }
};