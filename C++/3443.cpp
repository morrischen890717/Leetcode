class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        int cnt_n = 0, cnt_s = 0, cnt_e = 0, cnt_w = 0;
        for(char c: s){
            if(c == 'N')
                cnt_n++;
            else if(c == 'S')
                cnt_s++;
            else if(c == 'E')
                cnt_e++;
            else
                cnt_w++;
            int change_x = min(k, min(cnt_e, cnt_w)), change_y = min(k, min(cnt_n, cnt_s));
            ans = max(ans, abs(cnt_n - cnt_s) + abs(cnt_e - cnt_w) + 2 * min(k, change_x + change_y));
        }
        return ans;
    }
};