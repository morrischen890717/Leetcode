class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        /*
        using bottom-up DP
        reference: https://leetcode.com/problems/fair-distribution-of-cookies/solutions/2141573/dp-submask-enumeration-most-optimal-solution-100-faster-c/
        */
        int n = cookies.size();
        vector<vector<int>> dp(k + 1, vector<int> (1 << n, INT_MAX)); // dp[i][mask]: means distributing the cookies determined by the mask to the first i person
        dp[0][0] = 0;
        vector<int> sum(1 << n, 0);
        for(int i = 0; i < (1 << n); i++){
            for(int j = 0; j < n; j++){
                if(i & (1 << j))
                    sum[i] += cookies[j];
            }
        }
        for(int person = 1; person <= k; person++){
            for(int mask = 0; mask < (1 << n); mask++){
                for(int submask = mask; submask > 0; submask = (submask - 1) & mask){
                    // mask is divided into submask (for current person) and submask^mask (for the first (person-1) person)
                    dp[person][mask] = min(dp[person][mask], max(sum[submask], dp[person - 1][submask ^ mask]));
                }
            }
        }
        return dp[k][(1 << n) - 1];
    }
};