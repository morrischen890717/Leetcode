class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        // using bottom-up DP
        const int MOD = 1e9 + 7;
        unordered_map<int, int> dp;
        int ans = 0;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            double res = sqrt(arr[i]);
            int sqrt = floor(res);
            dp[arr[i]] = 1;
            for(int j = 0; j < i && arr[j] <= sqrt; j++){
                if(arr[i] % arr[j] == 0 && dp.count(arr[i] / arr[j]) > 0){
                    if(arr[j] == arr[i] / arr[j])
                        dp[arr[i]] += ((long long)dp[arr[j]] * dp[arr[i] / arr[j]]) % MOD;
                    else
                        dp[arr[i]] += ((long long)dp[arr[j]] * dp[arr[i] / arr[j]] * 2) % MOD; // *2 is because we can swap the left-subtree and right-subtree
                    dp[arr[i]] %= MOD;
                }
            }
            ans += dp[arr[i]];
            ans %= MOD;
        }
        return ans;
    }
};