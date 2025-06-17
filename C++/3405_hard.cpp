class Solution {
private:
    const int MOD = 1e9 + 7;
public:
    long long exp(long long base, long long k){
        long long res = 1;
        while(k){
            if(k % 2 == 1)
                res = (res * base) % MOD;
            base = (base * base) % MOD;
            k /= 2;
        }
        return res;
    }
    long long modInverse(long long x){
        return exp(x, MOD - 2);
    }
    long long combination(int n, int r, vector<long long>& fact){
        return fact[n] * modInverse(fact[r]) % MOD * modInverse(fact[n - r]) % MOD;
    }
    int countGoodArrays(int n, int m, int k) {
        /*
        using math
        reference:
        https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/solutions/6199457/too-hard-to-code-find-a-formula/?envType=daily-question&envId=2025-06-17
        https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/solutions/6199466/pure-maths-formula-derived-fully-explained-c/?envType=daily-question&envId=2025-06-17
        */
        vector<long long> fact(n + 1, 1);
        for(int i = 2; i <= n; i++){
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        long long res = combination(n - 1, k, fact);
        res = (res * m) % MOD;
        res = (res * exp(m - 1, n - k - 1)) % MOD;
        return res;
    }
};