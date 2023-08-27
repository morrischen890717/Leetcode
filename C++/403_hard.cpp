class Solution {
public:
    bool canCross(vector<int>& stones) {
        // using bottom-up DP
        // time complexity: O(N^2), space complexity: O(N^2)
        // reference: https://leetcode.com/problems/frog-jump/solutions/193816/concise-and-fast-dp-solution-using-2d-array-instead-of-hashmap-with-text-and-video-explanation/
        int n = stones.size();
        vector<vector<bool>> dp(n, vector<bool> (n, false)); // dp[id][diff] means that if the frog can jump diff units when it is on the id-th stone.
        dp[0][1] = true;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                int diff = stones[i] - stones[j];
                if(diff < 0 || diff >= n || !dp[j][diff])
                    continue;
                if(i == n - 1)
                    return true;
                dp[i][diff] = true;
                if(diff - 1 >= 0)
                    dp[i][diff - 1] = true;
                if(diff + 1 < n)
                    dp[i][diff + 1] = true;
            }
        }
        return false;
    }
};