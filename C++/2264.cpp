class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        char max_num = '0' - 1;
        int len = num.length();
        for(int i = 0; i < len - 2; i++){
            if(num[i] == num[i + 1] && num[i] == num[i + 2] && num[i] > max_num){
                max_num = num[i];
                ans = num.substr(i, 3);
            }
        }
        return ans;
    }
};