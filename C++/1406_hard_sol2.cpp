class Solution {
public:
    int canWin(vector<int>& stoneValue, int n, vector<int>& dp, int i){
        if(i >= n)
            return 0;
        if(dp[i] != INT_MIN)
            return dp[i];
        int sum = 0;
        for(int j = i; j < i + 3 && j < n; j++){
            sum += stoneValue[j];
            dp[i] = max(dp[i], sum - canWin(stoneValue, n, dp, j + 1));
        }
        return dp[i];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n, INT_MIN); // dp[i] means the value that person (could be either Alice or Bob) who does the first take from index i can win over another person
        int res = canWin(stoneValue, n, dp, 0);
        if(res > 0)
            return "Alice";
        else if(res < 0)
            return "Bob";
        return "Tie";
    }
};