class Solution {
public:
    int convert(char c){
        if(c == 'Q')
            return 0;
        else if(c == 'W')
            return 1;
        else if(c == 'E')
            return 2;
        return 3;
    }
    bool isValid(vector<int>& cnt, int num){
        for(int i = 0; i < cnt.size(); i++){
            if(cnt[i] > num)
                return false;
        }
        return true;
    }
    int balancedString(string s) {
        // using two-pointers and sliding window
        // time complexity: O(N), space complexity: O(1)
        int len = s.length();
        vector<int> cnt(4, 0);
        for(char c: s){
            cnt[convert(c)]++;
        }
        if(isValid(cnt, len / 4))
            return 0;
        int ans = len;
        int l = 0;
        for(int r = 0; r < len; r++){
            cnt[convert(s[r])]--;
            while(isValid(cnt, len / 4)){
                ans = min(ans, r - l + 1);
                cnt[convert(s[l])]++;
                l++;
            }
        }
        return ans;
    }
};