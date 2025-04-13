class Solution {
public:
    int countGoodNumbers(long long n) {
        int MOD = 1e9 + 7;
        if(n == 0)
            return 1;
        else if(n == 1)
            return 5;
        int remain = n % 2 ? 5 : 1;
        long long x = n / 2;
        if(x % 2){
            remain *= 20;
            x --;
        }
        int res = countGoodNumbers(x);
        return (long long)(((long long)res * res) % MOD) * remain % MOD;
    }
};