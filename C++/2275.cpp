class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans = 0;
        int n = candidates.size();
        vector<int> cnt(32, 0);
        for(int candidate: candidates){
            for(int i = 0; i < 32; i++){
                cnt[i] += (candidate & 1);
                candidate >>= 1;
            }
        }
        for(int num: cnt){
            ans = max(ans, num);
        }
        return ans;
    }
};