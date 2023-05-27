class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        // reference: https://leetcode.com/problems/stone-game-iii/solutions/564260/java-c-python-dp-o-1-space/
        int n = stoneValue.size();
        vector<int> dp(n + 1, INT_MIN); // dp[i] means the value that person (could be either Alice or Bob) who does the first take from index i can win over another person
        dp[n] = 0;
        for(int i = n - 1; i >= 0; i--){
            int sum = 0;
            for(int j = i; j < i + 3 && j < n; j++){
                sum += stoneValue[j];
                dp[i] = max(dp[i], sum - dp[j + 1]);
            }
        }
        if(dp[0] > 0)
            return "Alice";
        else if(dp[0] < 0)
            return "Bob";
        return "Tie";
    }
};