class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        int cnt = 9; // 1 ~ 9
        int ans = 0;
        ans += cnt;
        for(int i = 1; i < n; i++){
            cnt *= (10 - i);
            ans += cnt;
        }
        return ans + 1; // +1 is for number 0
    }
};