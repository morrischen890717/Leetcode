class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k)
            return false;
        int cnt = 0;
        for(char c: s){
            cnt ^= (1 << (c - 'a'));
        }
        while(cnt){
            if(cnt & 1)
                k--;
            cnt >>= 1;
        }
        return k >= 0;
    }
};