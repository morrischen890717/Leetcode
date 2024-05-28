class Solution {
public:
    int checkRecord(int n) {
        // using bottom-up DP
        // reference: https://leetcode.com/problems/student-attendance-record-ii/solutions/101643/share-my-o-n-c-dp-solution-with-thinking-process-and-explanation/?envType=daily-question&envId=2024-05-26
        if(n == 1)
            return 3;
        else if(n == 2)
            return 8;
        const int MOD = 1e9 + 7;
        vector<int> a(n + 1), l(n + 1), p(n + 1);
        a[1] = l[1] = p[1] = 1;
        a[2] = 2;
        l[2] = 3;
        a[3] = 4;
        for(int i = 2; i <= n; i++){
            p[i] = ((a[i - 1] + l[i - 1]) % MOD + p[i - 1]) % MOD;
            if(i >= 3)
                l[i] = (((p[i - 1] + a[i - 1]) % MOD + p[i - 2]) % MOD + a[i - 2]) % MOD;
            if(i >= 4)
                a[i] = ((a[i - 1] + a[i - 2]) % MOD + a[i - 3]) % MOD;
        }
        return ((p[n] + l[n]) % MOD + a[n]) % MOD;
    }
};