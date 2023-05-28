class Solution {
public:
    string removeTrailingZeros(string num) {
        int l, r;
        int len = num.length();
        for(int i = 0; i < len; i++){
            if(num[i] != '0'){
                l = i;
                break;
            }
        }
        for(int i = len - 1; i >= 0; i--){
            if(num[i] != '0'){
                r = i;
                break;
            }
        }
        string ans(num, l, r - l + 1);
        return ans;
    }
};