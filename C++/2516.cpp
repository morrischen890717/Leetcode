class Solution {
public:
    bool check(vector<int>& cnt){
        for(int num: cnt){
            if(num < 0)
                return false;
        }
        return true;
    }
    int takeCharacters(string s, int k) {
        // using sliding window
        // time complexity: O(N), space complexity: O(1)
        vector<int> cnt(3, 0);
        for(char c: s){
            cnt[c - 'a']++;
        }
        for(int& num: cnt){
            if(num < k)
                return -1;
            num -= k;
        }
        int len = s.length();
        int ans = len;
        int l = 0;
        for(int r = 0; r < len; r++){
            cnt[s[r] - 'a']--;
            while(l <= r && !check(cnt)){
                cnt[s[l++] - 'a']++;
            }
            ans = min(ans, len - (r - l + 1));
        }
        return ans;
    }
};