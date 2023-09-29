class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        // using bottom-up DP
        const int MOD = 1e9 + 7;
        vector<int> prev(target + 1, 0);
        prev[0] = 1;
        for(int i = 1; i <= n; i++){
            vector<int> cur(target + 1, 0);
            for(int j = 1; j <= k; j++){
                for(int t = j; t <= target; t++){
                    cur[t] += prev[t - j];
                    cur[t] %= MOD;
                }
            }
            prev = cur;
        }
        return prev[target];
    }
};