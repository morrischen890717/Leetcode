class Solution {
public:
    int countOrders(int n) {
        /*
        using math(combinatorics)
        time complexity: O(N)
        main idea:
        We have 2n seats in total, first we pick two of them and give it to the first order(between the picked two seats, P will always be in front of D), which has C(2n, 2) combinations, 
        then we pick two seats from rest of the seats and give it to second order, which has C(2n-2, 2) combinations, ..., 
        so the total possible sequences will be C(2n, 2) * C(2n-2, 2) * C(2n-4, 2) * ... * C(4, 2) * C(2, 2)
        */
        const int MOD = 1e9 + 7;
        int ans = 1;
        for(int i = 2 * n; i > 0; i -= 2){
            int combination = i * (i - 1) / 2;
            ans = (long long)ans * combination % MOD;
        }
        return ans;
    }
};