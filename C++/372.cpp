class Solution {
public:
    const int MOD = 1337;
    int power(int x, int pow){
        long long result = 1;
        for(int i = 0; i < pow; i++){
            result *= x;
            result %= MOD;
        }
        return result;
    }
    int superPow(int a, vector<int>& b) {
        /*
        reference: https://leetcode.com/problems/super-pow/solutions/84472/c-clean-and-short-solution/
        */
        if(b.empty())
            return 1;
        int last_digit = b.back();
        b.pop_back();
        return ((power(superPow(a, b), 10) % MOD) * (power(a, last_digit) % MOD) % MOD);
    }
};