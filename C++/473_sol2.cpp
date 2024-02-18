class Solution {
public:
    bool solve(vector<int>& matchsticks, vector<char>& dp, int used, int cur, int target, int edge_num){
        if(edge_num == 4)
            return true;
        if(cur == target)
            return solve(matchsticks, dp, used, 0, target, edge_num + 1);
        if(dp[used] != 0)
            return dp[used] == 1;
        int n = matchsticks.size();
        for(int i = 0; i < n; i++){
            if(used & (1 << i))
                continue;
            if(cur + matchsticks[i] <= target && solve(matchsticks, dp, used | (1 << i), cur + matchsticks[i], target, edge_num)){
                dp[used] = 1;
                return true;
            }
        }
        dp[used] = -1;
        return false;
    }
    bool makesquare(vector<int>& matchsticks) {
        // using top-down DP and bit manipulation
        int n = matchsticks.size();
        vector<char> dp(1 << n, 0);
        int sum = 0;
        for(int stick: matchsticks){
            sum += stick;
        }
        if(sum % 4)
            return false;
        int target = sum / 4;
        return solve(matchsticks, dp, 0, 0, target, 0);
    }
};