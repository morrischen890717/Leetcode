class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int exp5 = 1;
        int cnt5 = 0;
        while((exp5 *= 5) <= n){
            cnt5 = (cnt5 * 5) + 1;
            if(exp5 * 5 > n){
                n -= exp5;
                ans += cnt5;
                exp5 = 1;
                cnt5 = 0;
                if(n < 5)
                    break;
            }
        }
        return ans;
    }
};