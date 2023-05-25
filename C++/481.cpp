class Solution {
public:
    int magicalString(int n) {
        string s = "1";
        int len = 1;
        int ptr = 1;
        int next = 2, num = 2;
        while(len < n){
            s.append(num, '0' + next);
            len += num;
            ptr++;
            next ^= 3;
            num = s[ptr] - '0';
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1')
                cnt++;
        }
        return cnt;
    }
};