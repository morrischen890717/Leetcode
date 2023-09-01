class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> cnt(n + 1);
        for(int i = 0; i <= n; i++){
            cnt[i] = cnt[i / 2] + i % 2;
        }
        return cnt;
    }
};