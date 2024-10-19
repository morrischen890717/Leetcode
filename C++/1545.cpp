class Solution {
public:
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i = 1; i < n; i++){
            string tmp;
            for(int j = s.length() - 1; j >= 0; j--){
                tmp += s[j] == '0' ? '1' : '0';
            }
            s = s + "1" + tmp;
        }
        return s[k - 1];
    }
};