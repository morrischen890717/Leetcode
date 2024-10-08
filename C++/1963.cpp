class Solution {
public:
    int minSwaps(string s) {
        int swap = 0;
        int l = 0, r = s.length() - 1;
        int cnt_l = 0, cnt_r = 0;
        while(l <= r){
            bool swap_l = false, swap_r = false;
            if(s[l] == '['){
                cnt_l++;
                l++;
            }
            else if(cnt_l){
                cnt_l--;
                l++;
            }
            else
                swap_l = true;
            if(s[r] == ']'){
                cnt_r++;
                r--;
            }
            else if(cnt_r){
                cnt_r--;
                r--;
            }
            else
                swap_r = true;
            if(l < r && swap_l && swap_r){
                swap++;
                cnt_l++;
                cnt_r++;
                l++;
                r--;
            }
        }
        return swap;
    }
};