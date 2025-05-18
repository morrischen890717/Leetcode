class Solution {
public:
    int colorTheGrid(int m, int n) {
        // using bottom-up DP
        // reference: https://leetcode.com/problems/painting-a-grid-with-three-different-colors/solutions/6754794/dp-in-depth-with-images-example-walkthrough-c-python-java/?envType=daily-question&envId=2025-05-18
        const int MOD = 1e9 + 7;
        vector<vector<int>> dp(1005, vector<int> (250)), pattern(250);
        vector<vector<bool>> rowValid(250, vector<bool> (250, true));
        vector<int> good;
        int total = pow(3, m);
        for(int i = 0; i < total; i++){
            int val = i;
            bool valid = true;
            for(int j = 0; j < m; j++){
                pattern[i].push_back(val % 3);
                val /= 3;
            }
            for(int j = 1; j < m; j++){
                if(pattern[i][j] == pattern[i][j - 1])
                    valid = false;
            }
            if(valid)
                good.push_back(i);
        }
        for(int i: good){
            dp[0][i] = 1;
        }
        for(int i: good){
            for(int j: good){
                for(int k = 0; k < m; k++){
                    if(pattern[i][k] == pattern[j][k])
                        rowValid[i][j] = false;
                }
            }
        }
        for(int col = 1; col < n; col++){
            for(int i: good){
                for(int j: good){
                    if(rowValid[i][j]){
                        dp[col][i] += dp[col - 1][j];
                        dp[col][i] %= MOD;
                    }
                }
            }
        }
        int ans = 0;
        for(int i: good){
            ans += dp[n - 1][i];
            ans %= MOD;
        }
        return ans;
    }
};