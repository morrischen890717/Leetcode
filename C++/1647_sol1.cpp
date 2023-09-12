class Solution {
public:
    int minDeletions(string s) {
        // using sort and Greedy
        // time complexity: O(N), space complexity: O(1)
        int ans = 0;
        vector<int> cnt(26, 0);
        for(char c: s){
            cnt[c - 'a']++;
        }
        sort(cnt.begin(), cnt.end());
        for(int i = cnt.size() - 2; i >= 0; i--){
            if(cnt[i] > 0 && cnt[i] >= cnt[i + 1]){
                int tmp = max(0, cnt[i + 1] - 1);
                ans += cnt[i] - tmp;
                cnt[i] = tmp;
            }
        }
        return ans;
    }
};