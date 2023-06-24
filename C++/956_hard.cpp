class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        /*
        using DP
        reference: https://leetcode.com/problems/tallest-billboard/solutions/203181/java-c-python-dp-min-o-sn-2-o-3-n-2-n/
        */
        unordered_map<int, int> dp;
        dp[0] = 0;
        for(int rod: rods){
            unordered_map<int, int> m(dp);
            for(auto it: m){
                int d = it.first;
                dp[d + rod] = max(dp[d + rod], m[d]);
                dp[abs(d - rod)] = max(dp[abs(d - rod)], m[d] + min(d, rod));
            }
        }
        return dp[0];
    }
};