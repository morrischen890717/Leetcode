class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int len = s.length();
        string ans;
        vector<int> cnt(26, 0);
        int ptr = -1, appear = 0;
        for(char c: s){
            cnt[c - 'a']++;
            ptr = max(ptr, c - 'a');
        }
        while(ptr >= 0){
            if(appear == repeatLimit){
                int tmp = ptr - 1;
                while(tmp >= 0 && cnt[tmp] == 0){
                    tmp--;
                }
                if(tmp < 0)
                    break;
                else{
                    ans += 'a' + tmp;
                    cnt[tmp]--;
                    appear = 0;
                }
            }
            else{
                ans += 'a' + ptr;
                appear++;
                cnt[ptr]--;
            }
            while(ptr >= 0 && cnt[ptr] == 0){
                ptr--;
                appear = 0;
            }
        }
        return ans;
    }
};