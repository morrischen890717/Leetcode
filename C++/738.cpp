class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        int ans = 0;
        int prev = 10;
        int cnt = 0;
        while(n){
            int cur = n % 10;
            if(cur > prev){
                ans = cur * pow(10, cnt) - 1;
                prev = cur - 1;
            }
            else{
                ans = cur * pow(10, cnt) + ans;
                prev = cur;
            }
            cnt++;
            n /= 10;
        }
        return ans;
    }
};