class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n + 1);
        int ptr2, ptr3, ptr5;
        dp[1] = 1;
        ptr2 = ptr3 = ptr5 = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = min({dp[ptr2] * 2, dp[ptr3] * 3, dp[ptr5] * 5});
            if(dp[ptr2] * 2 == dp[i])
                ptr2++;
            if(dp[ptr3] * 3 == dp[i])
                ptr3++;
            if(dp[ptr5] * 5 == dp[i])
                ptr5++;
        }
        return dp[n];
    }
};